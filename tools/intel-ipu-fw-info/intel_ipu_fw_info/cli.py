import argparse
import dataclasses
import json
import os
import pathlib
from typing import BinaryIO

from .parser import ByteEncoder, FirmwareInfo, get_cse, get_firmware_info
from .spec import CSE


def parse_args() -> argparse.Namespace:
    parser: argparse.ArgumentParser = argparse.ArgumentParser()
    parser.add_argument('--full', action='store_true', help=f'show full info')
    parser.add_argument('firmware_path', metavar='<firmware.bin>', type=pathlib.Path, help='path to the firmware')
    return parser.parse_args()


def main() -> int:
    args: argparse.Namespace = parse_args()

    f: BinaryIO
    with open(args.firmware_path, 'rb') as f:
        firmware: bytes = f.read()
        info: CSE | FirmwareInfo = get_cse(firmware) if args.full else get_firmware_info(firmware)
    print(json.dumps(dataclasses.asdict(info), indent=2, cls=ByteEncoder))

    return os.EX_OK
