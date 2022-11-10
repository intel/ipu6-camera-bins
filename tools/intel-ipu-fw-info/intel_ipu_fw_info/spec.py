import dataclasses
import datetime
import decimal
import enum

from .key import Key


# JSONEncoder does not let us customize the serialization of int, thus we inherit Decimal instead
class bcddate(decimal.Decimal):
    def __repr__(self, *args, **kwargs) -> str:
        bcd_date_bytes: bytes = int(self).to_bytes(4, 'big')
        return '{}-{:02d}-{:02d}'.format(
            2000 + int(hex(bcd_date_bytes[1])[2:]),
            int(hex(bcd_date_bytes[2])[2:]),
            int(hex(bcd_date_bytes[3])[2:]))


class ComponentStructFormat(enum.StrEnum):
    CSE: 'ComponentStructFormat' = '4sIHBB4s'
    CSE_SUBCOMPONENT_HEADER: 'ComponentStructFormat' = '12sIII'
    CSS_BEGINNING_PIECE: 'ComponentStructFormat' = 'I'
    CSS_4_FIXED: 'ComponentStructFormat' = 'IIIIIII4sIHHHHIHHHH64sII'
    CSS_4_DATA: 'ComponentStructFormat' = '{modulus_size}s{exponent_size}s{signature_size}s'
    COMPONENT_EXTENSION_BEGINNING_PIECE: 'ComponentStructFormat' = 'II'
    PLATFORM_FIRMWARE_AUTHENTICATION_COMPONENT_EXTENSION: 'ComponentStructFormat' = '4sI16sI'


@dataclasses.dataclass
class Component:
    pass


@dataclasses.dataclass
class ComponentExtension(Component):
    type: int
    size: int
    extension_id: int


@dataclasses.dataclass
class OtherComponentExtension(ComponentExtension):
    pass


@dataclasses.dataclass
class PlatformFirmwareAuthenticationComponentExtension(ComponentExtension):
    name: bytes
    vcn: int
    bitmap: bytes
    svn: int


@dataclasses.dataclass
class CSESubcomponentHeader(Component):
    name: bytes
    offset: int
    size: int
    reserved: int


@dataclasses.dataclass(kw_only=True)
class CSE(Component):
    signature: bytes = b'$CPD'
    num_subcomponent: int
    header_version: int
    header_length: int
    checksum: int
    partition_name: bytes
    subcomponent_headers: list[CSESubcomponentHeader]
    subcomponents: list[Component]


@dataclasses.dataclass
class CSS(Component):
    type: int


@dataclasses.dataclass
class CSS4(CSS):
    header_length: int
    header_version: int
    reserved_0: int
    mod_vendor: int
    date: bcddate
    size: int
    header_id: bytes
    padding: int
    firmware_version: tuple[int, int, int, int]
    svn: int
    meu_version: tuple[int, int, int, int]
    reserved_1: bytes
    modulus_size: int
    exponent_size: int
    modulus: bytes  # 4 times modulus_size
    exponent: bytes  # 4 times exponent_size
    signature: bytes  # 4 times modulus_size
    extensions: list[ComponentExtension]


@dataclasses.dataclass
class FirmwareInfo:
    timestamp: datetime.date
    version: str
    key: Key
