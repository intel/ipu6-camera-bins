import datetime
import json
import string
import struct
from typing import Any

from .key import Key, get_key_enum
from .spec import (
    FirmwareInfo,
    ComponentStructFormat,
    CSE,
    CSESubcomponentHeader,
    CSS,
    CSS4,
    Component,
    ComponentExtension,
    OtherComponentExtension,
    PlatformFirmwareAuthenticationComponentExtension,
    bcddate)


class ByteEncoder(json.JSONEncoder):
    def default(self, obj: Any) -> Any:
        if isinstance(obj, bytes | bytearray):
            b: bytes
            if all(b in string.printable.encode() for b in obj):
                return obj.decode()
            return ' '.join(map(lambda b: '{:02X}'.format(b), obj))
        if isinstance(obj, bcddate):
            return repr(obj)
        if isinstance(obj, Key | datetime.date | datetime.datetime):
            return str(obj)
        return super().default(obj)


def get_css_4(block: bytes, block_size: int) -> CSS4:
    type_: int
    header_length: int
    header_version: int
    reserved_0: int
    mod_vendor: int
    date: int
    size: int
    header_id: bytes
    padding: int
    firmware_version: tuple[int, int, int, int]
    firmware_version_0: int
    firmware_version_1: int
    firmware_version_2: int
    firmware_version_3: int
    svn: int
    meu_version: tuple[int, int, int, int]
    meu_version_0: int
    meu_version_1: int
    meu_version_2: int
    meu_version_3: int
    reserved_1: bytes
    modulus_size: int
    exponent_size: int
    (type_, header_length, header_version, reserved_0, mod_vendor, date, size, header_id, padding,
     firmware_version_0, firmware_version_1, firmware_version_2, firmware_version_3, svn, meu_version_0,
     meu_version_1, meu_version_2, meu_version_3, reserved_1, modulus_size, exponent_size) = struct.unpack(
        ComponentStructFormat.CSS_4_FIXED, block[:struct.calcsize(ComponentStructFormat.CSS_4_FIXED)])
    bcd_date: bcddate = bcddate(date)

    firmware_version = (firmware_version_0, firmware_version_1, firmware_version_2, firmware_version_3)
    meu_version = (meu_version_0, meu_version_1, meu_version_2, meu_version_3)

    signature_format: str = ComponentStructFormat.CSS_4_DATA.format(
        modulus_size=modulus_size * 4, exponent_size=exponent_size * 4, signature_size=modulus_size * 4)
    modulus: bytes
    exponent: bytes
    signature: bytes
    (modulus, exponent, signature) = struct.unpack(
        signature_format, block[struct.calcsize(ComponentStructFormat.CSS_4_FIXED):struct.calcsize(
            ComponentStructFormat.CSS_4_FIXED + signature_format)])

    extensions: list[ComponentExtension] = list()
    extension_index: int = 0
    current_offset: int = struct.calcsize(ComponentStructFormat.CSS_4_FIXED + signature_format)
    extension_type: int
    extension_size: int
    while current_offset < block_size:
        (extension_type, extension_size) = struct.unpack(
            ComponentStructFormat.COMPONENT_EXTENSION_BEGINNING_PIECE,
            block[current_offset:current_offset + struct.calcsize(
                ComponentStructFormat.COMPONENT_EXTENSION_BEGINNING_PIECE)])
        if extension_type == 0xFFFFFFFF:
            current_offset += 4
            continue
        extension: ComponentExtension = get_component_extension(block[current_offset:], extension_index)
        extensions.append(extension)
        extension_index += 1
        current_offset += extension_size

    return CSS4(
        type=type_, header_length=header_length, header_version=header_version, reserved_0=reserved_0,
        mod_vendor=mod_vendor, date=bcd_date, size=size, header_id=header_id, padding=padding,
        firmware_version=firmware_version, svn=svn, meu_version=meu_version, reserved_1=reserved_1,
        modulus_size=modulus_size, exponent_size=exponent_size, modulus=modulus, exponent=exponent, signature=signature,
        extensions=extensions)


def get_css(block: bytes, block_size: int) -> CSS:
    version: int
    (version,) = struct.unpack(
        ComponentStructFormat.CSS_BEGINNING_PIECE,
        block[:struct.calcsize(ComponentStructFormat.CSS_BEGINNING_PIECE)])

    if version == 4:
        return get_css_4(block, block_size)

    raise ValueError('unsupported CSS')


def get_cse_subcomponent_headers(block: bytes, num: int = 0) -> list[CSESubcomponentHeader]:
    res: list[CSESubcomponentHeader] = list()

    for _ in range(num):
        name: bytes
        data_offset: int
        data_size: int
        reserved: int
        (name, data_offset, data_size, reserved) = struct.unpack(
            ComponentStructFormat.CSE_SUBCOMPONENT_HEADER,
            block[:struct.calcsize(ComponentStructFormat.CSE_SUBCOMPONENT_HEADER)])
        name = name.rstrip(b'\0')
        block = block[struct.calcsize(ComponentStructFormat.CSE_SUBCOMPONENT_HEADER):]
        res.append(CSESubcomponentHeader(name=name, offset=data_offset, size=data_size, reserved=reserved))
    return res


def get_component_extension(block: bytes, extension_id: int) -> ComponentExtension:
    type_: int
    size: int
    (type_, size) = struct.unpack(
        ComponentStructFormat.COMPONENT_EXTENSION_BEGINNING_PIECE,
        block[:struct.calcsize(ComponentStructFormat.COMPONENT_EXTENSION_BEGINNING_PIECE)])

    if type_ == 15:
        name: bytes
        vcn: int
        bitmap: bytes
        svn: int
        (name, vcn, bitmap, svn) = struct.unpack(
            ComponentStructFormat.PLATFORM_FIRMWARE_AUTHENTICATION_COMPONENT_EXTENSION,
            block[:struct.calcsize(ComponentStructFormat.PLATFORM_FIRMWARE_AUTHENTICATION_COMPONENT_EXTENSION)])
        return PlatformFirmwareAuthenticationComponentExtension(
            type=type_, size=size, name=name, vcn=vcn, bitmap=bitmap, svn=svn, extension_id=extension_id)
    return OtherComponentExtension(type=type_, size=size, extension_id=extension_id)


def get_cse_subcomponents(block: bytes, headers: list[CSESubcomponentHeader]) -> list[Component]:
    res: list[Component] = list()

    header: CSESubcomponentHeader
    for header in headers:
        if header.name.endswith(b'.man'):
            res.append(get_css(block[header.offset:], header.size))
            continue
        res.append(get_component_extension(block[header.offset:], header.size))
    return res


def get_cse(block: bytes) -> CSE:
    if not block.startswith(CSE.signature):
        raise ValueError('not recognized firmware')

    signature: bytes
    num_subcomponent: int
    header_version: int
    header_length: int
    checksum: int
    partition_name: bytes
    (signature, num_subcomponent, header_version, header_length, checksum, partition_name) = struct.unpack(
        ComponentStructFormat.CSE, block[:struct.calcsize(ComponentStructFormat.CSE)])

    cse_subcomponent_headers: list[CSESubcomponentHeader] = get_cse_subcomponent_headers(
        block[header_length:], num=num_subcomponent)
    cse_subcomponents: list[Component] = get_cse_subcomponents(block, headers=cse_subcomponent_headers)

    return CSE(
        signature=signature,
        num_subcomponent=num_subcomponent,
        header_version=header_version,
        header_length=header_length,
        checksum=checksum,
        partition_name=partition_name,
        subcomponent_headers=cse_subcomponent_headers,
        subcomponents=cse_subcomponents)


def get_firmware_info(block: bytes) -> FirmwareInfo:
    cse: CSE = get_cse(block)

    return FirmwareInfo(
        timestamp=datetime.date.fromisoformat(repr(cse.subcomponents[0].date)),
        version='.'.join(map(str, cse.subcomponents[0].firmware_version)),
        key=get_key_enum(cse.subcomponents[0].modulus))
