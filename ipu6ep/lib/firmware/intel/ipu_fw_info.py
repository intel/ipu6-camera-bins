#!/usr/bin/env python3
# SPDX-License-Identifier: BSD-3-Clause
#
# Copyright (c) 2020, Intel Corporation. All rights reserved.
#

# pylint: disable=too-few-public-methods
# pylint: disable=too-many-arguments
# pylint: disable=too-many-instance-attributes

import sys
import argparse
import struct

# Public keys signatures recognized by parse_css_manifest()
# - add a new one as array of bytes and append entry to KNOWN_KEYS below.

TGL_PROD_KEY = bytes([0x4d, 0xe2, 0x0c, 0xd3, 0x7d, 0x1c, 0x27, 0x9a,
                      0x30, 0x81, 0xed, 0x27, 0x55, 0x92, 0x95, 0xb6,
                      0xd9, 0xa8, 0xd6, 0x96, 0x11, 0x0c, 0x5b, 0x48,
                      0xa2, 0x4a, 0x28, 0x8f, 0xa6, 0x0c, 0xb8, 0xbb,
                      0x61, 0xf2, 0x1a, 0x1b, 0x7c, 0xf7, 0x76, 0xb1,
                      0xe5, 0x94, 0x8d, 0xa6, 0xf3, 0x6d, 0x9b, 0xc7,
                      0x83, 0xf5, 0xaf, 0xca, 0x73, 0x49, 0x4a, 0xe5,
                      0x77, 0xf7, 0x1e, 0xd6, 0x4a, 0x76, 0x75, 0x15,
                      0x18, 0x25, 0xd6, 0x87, 0x26, 0x39, 0xaf, 0xd0,
                      0xd5, 0x80, 0x05, 0x19, 0x72, 0x4f, 0xf4, 0xda,
                      0x4c, 0xc4, 0x72, 0x7b, 0x43, 0x24, 0x54, 0x6d,
                      0x4a, 0xd4, 0xdb, 0x2f, 0xbb, 0xd2, 0xb8, 0xd4,
                      0x6c, 0x1f, 0x5c, 0x9f, 0xcf, 0x90, 0xb9, 0x4f,
                      0xa5, 0x5f, 0x0b, 0x67, 0x25, 0xf7, 0x0a, 0x90,
                      0x32, 0x4e, 0x2b, 0x1a, 0xe4, 0x3f, 0xaf, 0xab,
                      0x0a, 0x61, 0x45, 0x0b, 0xdd, 0xf9, 0x82, 0x4a,
                      0x6b, 0xa1, 0x10, 0xff, 0x46, 0xec, 0xb8, 0x80,
                      0xef, 0x61, 0x35, 0xe8, 0x72, 0x5c, 0x24, 0x63,
                      0x5f, 0x1e, 0x65, 0xfc, 0x29, 0x0f, 0xd7, 0xc7,
                      0xfb, 0xcf, 0x3d, 0xab, 0x7c, 0xf2, 0x03, 0xe9,
                      0x96, 0x25, 0xc7, 0xd4, 0x66, 0x04, 0x95, 0x8d,
                      0xbe, 0xe5, 0xc2, 0xee, 0x04, 0x7b, 0x2d, 0x0e,
                      0x8a, 0x93, 0x9e, 0x9b, 0xa2, 0xf0, 0x9c, 0x36,
                      0xcd, 0x27, 0x17, 0xfc, 0xfc, 0x10, 0x15, 0x47,
                      0x6d, 0x4d, 0x61, 0xfb, 0x69, 0x8b, 0x6e, 0xa8,
                      0xa2, 0x7c, 0xc1, 0x87, 0x1c, 0x7d, 0x10, 0xb4,
                      0xec, 0x4f, 0xce, 0xa6, 0xd1, 0xa2, 0xc4, 0x74,
                      0x65, 0x05, 0x94, 0x03, 0x63, 0xf8, 0x1c, 0xd1,
                      0x6e, 0x69, 0x0f, 0xd4, 0x34, 0x10, 0x02, 0xf7,
                      0x71, 0x0d, 0x81, 0x12, 0xde, 0x7d, 0xb1, 0xdb,
                      0xc0, 0x32, 0x4d, 0x3e, 0xe0, 0x45, 0xa3, 0x1d,
                      0x41, 0x6f, 0xe3, 0x35, 0x81, 0x8e, 0xb7, 0x7a,
                      0x7a, 0x2a, 0xb5, 0x1a, 0xc6, 0xed, 0x73, 0x09,
                      0xa1, 0xbb, 0x5e, 0xe9, 0x77, 0x3a, 0x36, 0x98,
                      0x8e, 0xde, 0xe2, 0x9b, 0x6e, 0x73, 0x68, 0x5e,
                      0xea, 0x52, 0x4b, 0x7e, 0xa2, 0x0e, 0x40, 0xc7,
                      0x00, 0x3f, 0x09, 0xf9, 0x33, 0x32, 0x23, 0xbe,
                      0xb5, 0x00, 0x6b, 0x4f, 0x68, 0x5d, 0x76, 0x14,
                      0x12, 0xd6, 0x90, 0xa6, 0xff, 0xb8, 0xfc, 0x50,
                      0xe5, 0x62, 0x94, 0xc3, 0x7c, 0xe8, 0x77, 0xf9,
                      0x7c, 0xb5, 0x5f, 0xed, 0x98, 0x80, 0xcc, 0xc1,
                      0x1a, 0xa1, 0x61, 0x2d, 0xea, 0x39, 0x49, 0xa3,
                      0xb7, 0xdb, 0xb3, 0x15, 0x47, 0xfc, 0x2f, 0x12,
                      0x1c, 0x33, 0xe8, 0x31, 0x71, 0xb7, 0x5a, 0xc7,
                      0x63, 0x83, 0xa8, 0xa9, 0x6d, 0xfa, 0x40, 0x9c,
                      0xe5, 0x9c, 0x5e, 0x76, 0x2b, 0x9c, 0xd3, 0x6b,
                      0x73, 0xd4, 0xf3, 0xa3, 0x49, 0xf6, 0x86, 0x85,
                      0x96, 0x73, 0xa8, 0x31, 0xc8, 0x66, 0xfe, 0x9c])

TGL_DEBUG_KEY = bytes([0xa3, 0x51, 0xb7, 0x28, 0xe6, 0x4b, 0xb5, 0x07,
                       0x87, 0xff, 0xc9, 0x7b, 0x15, 0x1b, 0x2c, 0x94,
                       0xbc, 0x85, 0x3e, 0xe9, 0x4b, 0xb2, 0xa9, 0xc9,
                       0x5c, 0xa8, 0xc9, 0x33, 0xf7, 0x07, 0x71, 0x72,
                       0x1f, 0xf6, 0x41, 0x13, 0x44, 0xe7, 0x5b, 0x8a,
                       0xb0, 0x58, 0xdc, 0x47, 0x64, 0x5b, 0x34, 0x88,
                       0xf2, 0x11, 0xd0, 0x17, 0x58, 0x2d, 0xae, 0x79,
                       0x2c, 0x1d, 0xb7, 0xf2, 0x3e, 0xf9, 0x80, 0x80,
                       0x93, 0xf5, 0xc2, 0xdc, 0xf5, 0x3c, 0x5a, 0x50,
                       0xa7, 0x04, 0x74, 0x59, 0xba, 0xce, 0x15, 0x85,
                       0x05, 0xd0, 0x52, 0xf8, 0xee, 0x1b, 0x93, 0xc8,
                       0x41, 0x41, 0xf5, 0x83, 0xa8, 0xb2, 0xf5, 0x55,
                       0x97, 0x66, 0xfc, 0x81, 0x7f, 0x43, 0x40, 0x6b,
                       0x46, 0xa5, 0xc5, 0x1a, 0xef, 0x81, 0x6d, 0xab,
                       0x2a, 0x0e, 0x7b, 0x13, 0xfc, 0x8e, 0x57, 0x78,
                       0x5a, 0x63, 0xb7, 0xe5, 0x9b, 0x45, 0x51, 0x42,
                       0x3c, 0x57, 0x2f, 0x80, 0x41, 0x77, 0x7c, 0xe6,
                       0x78, 0xcb, 0x24, 0x88, 0x4d, 0xe0, 0xc1, 0xeb,
                       0x6d, 0xd9, 0x05, 0x8f, 0xfc, 0xe8, 0x74, 0x3e,
                       0x01, 0xb1, 0xe1, 0x89, 0x9b, 0x6c, 0xad, 0x47,
                       0x38, 0xb1, 0xce, 0xbe, 0x49, 0x7b, 0x65, 0x7a,
                       0x7e, 0x9e, 0x3f, 0x24, 0xb3, 0x2e, 0xdb, 0x35,
                       0x77, 0x5a, 0x31, 0x75, 0xcf, 0xe1, 0x71, 0x98,
                       0xbd, 0x61, 0x24, 0xd4, 0xd2, 0x97, 0xfd, 0xd0,
                       0xbe, 0xeb, 0x0f, 0xbc, 0x60, 0xd7, 0x34, 0x1b,
                       0x8e, 0x55, 0x5f, 0xf7, 0xef, 0xf6, 0x03, 0xea,
                       0x60, 0xba, 0x34, 0x9f, 0xef, 0x52, 0x38, 0xc3,
                       0xe6, 0xac, 0x08, 0x68, 0x64, 0xf1, 0x3c, 0x16,
                       0x14, 0x03, 0xbf, 0xaa, 0x60, 0x01, 0x27, 0x0c,
                       0x4e, 0xb6, 0x03, 0xff, 0x45, 0xdd, 0x2b, 0xfd,
                       0xf1, 0x86, 0xb7, 0x43, 0x83, 0x67, 0x1e, 0x1f,
                       0x33, 0x9e, 0xc7, 0x17, 0xb6, 0xef, 0x87, 0x91,
                       0x02, 0x60, 0x59, 0x4f, 0x8b, 0x97, 0x19, 0x9c,
                       0x37, 0xfa, 0x4b, 0xef, 0x09, 0xc9, 0x3e, 0x06,
                       0x68, 0x78, 0x2c, 0x13, 0x90, 0x7f, 0x1c, 0xc2,
                       0x5a, 0x31, 0xb6, 0x64, 0x7c, 0xcc, 0x42, 0xc7,
                       0xce, 0x15, 0x50, 0x3a, 0xe7, 0x26, 0x6a, 0xe2,
                       0x08, 0x7f, 0x47, 0x40, 0x7f, 0x0b, 0x3a, 0x6d,
                       0x94, 0x24, 0x59, 0xef, 0xdf, 0x68, 0x24, 0x01,
                       0x96, 0x00, 0xea, 0xe7, 0x2b, 0xc3, 0xa5, 0xb9,
                       0x65, 0x60, 0x97, 0xd7, 0x61, 0x7f, 0xbf, 0xe8,
                       0x33, 0x1b, 0xf5, 0x51, 0xf4, 0x0c, 0x6b, 0x80,
                       0x29, 0x7d, 0xf3, 0xbb, 0x26, 0xf0, 0x99, 0xd3,
                       0x3b, 0xca, 0x6d, 0x84, 0x8d, 0x04, 0xf8, 0x18,
                       0x27, 0x02, 0x04, 0x9d, 0x17, 0xa6, 0xce, 0x8d,
                       0xd7, 0x96, 0x29, 0xac, 0x27, 0x5f, 0x40, 0x41,
                       0x88, 0x09, 0xc0, 0x24, 0x7e, 0x84, 0xb7, 0x5d,
                       0xe3, 0x85, 0x50, 0x58, 0x98, 0x08, 0xc1, 0xf7])

JSL_PROD_KEY = bytes([0xd1, 0x49, 0xdd, 0x52, 0xbc, 0x95, 0x97, 0xde,
                      0xc1, 0x6b, 0x51, 0x60, 0x41, 0x59, 0x05, 0x05,
                      0xe7, 0x16, 0xc7, 0x3b, 0x98, 0xeb, 0x0c, 0x09,
                      0xa3, 0x52, 0x6c, 0x67, 0xc8, 0x66, 0x26, 0x90,
                      0x13, 0x6b, 0x06, 0xaf, 0x91, 0x5c, 0x77, 0x7f,
                      0x0f, 0xbd, 0x54, 0xaf, 0xca, 0xaf, 0xaf, 0xf7,
                      0xca, 0xcc, 0x7e, 0xcb, 0x59, 0xea, 0xc1, 0xe1,
                      0x01, 0x65, 0x9b, 0x0b, 0x21, 0xc0, 0x6d, 0xd7,
                      0x5f, 0x31, 0x52, 0x62, 0xce, 0xd1, 0x97, 0x22,
                      0x17, 0x91, 0xcf, 0xc4, 0x99, 0xd1, 0xb2, 0xa7,
                      0x41, 0xd4, 0xe3, 0x7d, 0x71, 0x9d, 0x22, 0xc1,
                      0x98, 0x1d, 0x3e, 0x42, 0xc3, 0xf4, 0x88, 0x98,
                      0xa8, 0x9a, 0xe5, 0xc2, 0xd3, 0x57, 0xd4, 0xcc,
                      0x1d, 0xaa, 0x67, 0x3a, 0xdf, 0x12, 0x4a, 0x3b,
                      0xda, 0xb0, 0x7c, 0xe8, 0x78, 0x5a, 0x9f, 0x9d,
                      0x7b, 0x82, 0x25, 0xbd, 0x9d, 0xc5, 0x93, 0x0d,
                      0xa1, 0xa9, 0xb9, 0xbe, 0xc2, 0xa4, 0x66, 0x7e,
                      0x8b, 0xac, 0x84, 0x5d, 0xcf, 0x17, 0x6e, 0xe2,
                      0x66, 0x79, 0x96, 0xec, 0x2e, 0xdd, 0xc6, 0xaf,
                      0x5d, 0xba, 0xd0, 0x33, 0x2a, 0xdf, 0x3f, 0xfc,
                      0x5b, 0xf4, 0x10, 0x27, 0x59, 0x7e, 0x69, 0x93,
                      0x4b, 0x48, 0x1c, 0x3e, 0x5b, 0x6b, 0x73, 0x1a,
                      0xa1, 0x24, 0x2e, 0xfd, 0x2d, 0x74, 0x9b, 0xe3,
                      0xe3, 0xc1, 0xb6, 0x3c, 0xe5, 0xd6, 0x07, 0xaa,
                      0xda, 0x12, 0x6c, 0x18, 0x19, 0x02, 0x26, 0xa0,
                      0xfd, 0x70, 0x0d, 0xfc, 0xbd, 0x05, 0x20, 0xd2,
                      0xc4, 0x04, 0x85, 0xc2, 0x2b, 0x98, 0xea, 0x52,
                      0x5f, 0x5e, 0x38, 0x44, 0xd7, 0x01, 0xfc, 0xc7,
                      0xea, 0x02, 0x11, 0x3f, 0xe8, 0x98, 0x33, 0x97,
                      0x87, 0xc9, 0x83, 0x1b, 0xfb, 0xef, 0x94, 0x5c,
                      0xba, 0xb6, 0x75, 0x9a, 0x89, 0x24, 0x78, 0xa0,
                      0xd7, 0xe6, 0x60, 0x01, 0x1e, 0xb5, 0x9c, 0x95])

JSL_DEBUG_KEY = bytes([0xdf, 0xf4, 0x1c, 0xfd, 0x41, 0x1b, 0x66, 0x77,
                       0x76, 0x0d, 0x64, 0xcc, 0x9e, 0x28, 0x07, 0xbc,
                       0x2d, 0xd1, 0x84, 0x8c, 0x55, 0xe2, 0x58, 0x31,
                       0xd7, 0x86, 0x69, 0x7a, 0x95, 0x56, 0x1a, 0xb6,
                       0x41, 0x67, 0x7d, 0x3c, 0x56, 0x1b, 0x68, 0x5c,
                       0x17, 0x95, 0xfe, 0x21, 0xcd, 0xbd, 0x86, 0x26,
                       0x27, 0x36, 0xac, 0xdc, 0x67, 0x68, 0x29, 0x11,
                       0xbd, 0xa4, 0xe9, 0xf9, 0x2b, 0x33, 0xe8, 0xb1,
                       0x9e, 0xe2, 0x67, 0xe2, 0x92, 0x31, 0x13, 0xaa,
                       0x37, 0xf8, 0x70, 0x45, 0xed, 0x02, 0x37, 0x48,
                       0x0c, 0x6c, 0x6d, 0x81, 0x61, 0xf2, 0x7d, 0xe8,
                       0x6e, 0x3f, 0x6e, 0xde, 0x6c, 0xcf, 0xe7, 0xa5,
                       0x1b, 0xef, 0x4d, 0xcd, 0xfc, 0x61, 0x0f, 0x19,
                       0x1a, 0xa8, 0xbe, 0xb8, 0xee, 0x4e, 0x43, 0x3e,
                       0x16, 0x96, 0xa9, 0xb7, 0xd1, 0x02, 0x8b, 0x2b,
                       0x5a, 0xb7, 0x67, 0x8a, 0xe2, 0x14, 0x47, 0xcf,
                       0x24, 0x9c, 0x0c, 0xb7, 0x26, 0x44, 0xcc, 0xf8,
                       0x8f, 0xd7, 0x25, 0xbc, 0xac, 0xb6, 0x31, 0xfe,
                       0x25, 0xf1, 0x9a, 0x91, 0xa6, 0x19, 0x6e, 0x26,
                       0x9c, 0xf6, 0x6b, 0x43, 0x77, 0x2a, 0x28, 0x67,
                       0x65, 0x24, 0xf9, 0x31, 0x53, 0xe1, 0x06, 0xd4,
                       0x1a, 0x2f, 0x30, 0x5d, 0x40, 0x8b, 0xdf, 0xe0,
                       0xb9, 0xf0, 0xc5, 0x9e, 0x6d, 0xd3, 0x41, 0x12,
                       0x10, 0x94, 0x8a, 0xbf, 0x7f, 0x93, 0x42, 0x89,
                       0x6e, 0xc5, 0xba, 0x85, 0xb9, 0xa2, 0xdd, 0xd8,
                       0x22, 0x6a, 0x6f, 0x2a, 0x7d, 0x10, 0x4d, 0xd6,
                       0xe7, 0x13, 0xc7, 0x13, 0xb1, 0xfb, 0x7b, 0x90,
                       0xe6, 0x42, 0x80, 0x42, 0xe1, 0xd0, 0xc8, 0xfa,
                       0x23, 0x09, 0x9e, 0xc9, 0x9a, 0x38, 0x2a, 0x10,
                       0x9a, 0x45, 0x44, 0x63, 0xe8, 0x88, 0x41, 0xab,
                       0x26, 0xb7, 0x01, 0x98, 0xe8, 0x22, 0xc3, 0x23,
                       0x90, 0xfb, 0x11, 0x11, 0x65, 0xf0, 0xea, 0x9f])

ADL_PROD_KEY = bytes([0xc3, 0xa9, 0x32, 0xd6, 0xcf, 0xe6, 0xab, 0xb0,
                      0xea, 0xa5, 0x48, 0x13, 0x48, 0xc7, 0x58, 0xf5,
                      0xe4, 0x66, 0xeb, 0x82, 0x2c, 0xf5, 0x7a, 0xbd,
                      0x73, 0x94, 0x45, 0x98, 0xb0, 0x92, 0x79, 0x4f,
                      0x57, 0x86, 0xf5, 0x9c, 0x1b, 0x6c, 0x45, 0x16,
                      0x22, 0x97, 0xa0, 0xb4, 0x6e, 0x1e, 0x42, 0x30,
                      0xb3, 0x3d, 0xf1, 0x9c, 0x3e, 0xd4, 0xcf, 0x7e,
                      0xf2, 0x6b, 0x82, 0xc2, 0x75, 0x9d, 0xaf, 0x1c,
                      0x74, 0xf1, 0xc1, 0x15, 0x9a, 0xa5, 0x09, 0xe2,
                      0xee, 0x48, 0x9a, 0x25, 0xba, 0x9a, 0x96, 0xbe,
                      0x28, 0xd7, 0xaf, 0xec, 0xc5, 0xcc, 0xc2, 0x70,
                      0xba, 0x6d, 0xeb, 0xdd, 0x7d, 0x6a, 0x47, 0xdc,
                      0x70, 0xed, 0xe9, 0x20, 0x00, 0x5f, 0xcb, 0x28,
                      0x80, 0x63, 0x87, 0x06, 0x18, 0xbb, 0x09, 0xec,
                      0xbf, 0x83, 0x1c, 0x7f, 0xd4, 0x8c, 0x3c, 0xac,
                      0xd9, 0x90, 0xde, 0x50, 0xed, 0x20, 0xab, 0xc3,
                      0xb7, 0xcc, 0xe3, 0x27, 0x92, 0xe9, 0x25, 0x74,
                      0xea, 0x42, 0x1b, 0x43, 0xb9, 0xeb, 0xf4, 0xd5,
                      0x2c, 0xdc, 0xa8, 0xf5, 0x4c, 0x05, 0xab, 0x34,
                      0x64, 0x73, 0xea, 0xe7, 0x7f, 0x1d, 0x9a, 0xe2,
                      0x86, 0x72, 0x98, 0x9a, 0x2f, 0x4c, 0x49, 0xa5,
                      0xbe, 0x8d, 0xa7, 0x96, 0x63, 0x08, 0x35, 0x89,
                      0x8e, 0xd3, 0xe9, 0x4e, 0xf1, 0x06, 0xa5, 0x3a,
                      0x5b, 0x28, 0x82, 0xd2, 0x9d, 0x9d, 0xd0, 0x3c,
                      0x7d, 0xce, 0xe1, 0xeb, 0x04, 0xb7, 0xf1, 0xd4,
                      0x2f, 0x68, 0xc2, 0xfb, 0x31, 0x08, 0x08, 0x7f,
                      0xb1, 0x30, 0x95, 0xd1, 0xce, 0xe6, 0xf3, 0xae,
                      0x84, 0x30, 0xf0, 0x13, 0xd0, 0xf8, 0xe5, 0xee,
                      0x02, 0xb7, 0xfd, 0x4f, 0xa8, 0xb3, 0x06, 0x1e,
                      0xf0, 0x8c, 0xce, 0xe1, 0x9d, 0xb1, 0xdc, 0x8e,
                      0x3d, 0xc6, 0xd6, 0x7c, 0xe1, 0xfc, 0xd4, 0xa3,
                      0x1c, 0x70, 0x9a, 0xf5, 0x31, 0xd6, 0x8e, 0xe7,
                      0x50, 0xae, 0xcc, 0xd7, 0x5c, 0xa7, 0xc2, 0xe6,
                      0xed, 0x7f, 0x0e, 0x1e, 0x91, 0x5c, 0x48, 0x70,
                      0x3e, 0x7a, 0xa7, 0xc9, 0x83, 0x97, 0x97, 0xc3,
                      0x04, 0xf4, 0x59, 0x74, 0x5b, 0xf2, 0x3c, 0x79,
                      0x8c, 0xf3, 0x63, 0xc8, 0xf4, 0x71, 0x6e, 0x08,
                      0xc0, 0x79, 0xaf, 0x8c, 0xe5, 0xf4, 0x0a, 0x53,
                      0x42, 0x68, 0x4b, 0xce, 0xad, 0x4e, 0xb4, 0x0c,
                      0xc5, 0x47, 0xdf, 0x86, 0x69, 0xa0, 0xad, 0xdc,
                      0x65, 0x6e, 0x3e, 0xf4, 0x9a, 0xc9, 0xbf, 0x24,
                      0x22, 0x0f, 0xb9, 0x08, 0x58, 0xe8, 0x96, 0x47,
                      0x70, 0x48, 0x3f, 0x4f, 0xb0, 0x96, 0xac, 0x9e,
                      0xf8, 0x3f, 0x6c, 0x2a, 0xc3, 0xea, 0x4e, 0xb8,
                      0x60, 0x55, 0xc4, 0x77, 0x7b, 0x81, 0x77, 0x3e,
                      0xe6, 0x69, 0x98, 0xe8, 0x3c, 0x6a, 0xd7, 0xca,
                      0x5b, 0x6f, 0xdc, 0xde, 0x73, 0x19, 0xf3, 0xa2,
                      0xd0, 0x2e, 0x01, 0xf0, 0xfd, 0xfd, 0xa9, 0xbb])

KNOWN_KEYS = {TGL_PROD_KEY : 'TGL prod key',
              TGL_DEBUG_KEY : 'TGL debug key',
	      JSL_PROD_KEY : 'JSL prod key',
              JSL_DEBUG_KEY : 'JSL debug key',
              ADL_PROD_KEY : 'ADL prod key'}

def parse_params():
    """ Parses parameters
    """
    parser = argparse.ArgumentParser(description='FW Binary Info Utility')
    parser.add_argument('-v', '--verbose', help='increase output verbosity',
                        action='store_true')
    parser.add_argument('--headers', help='display headers only',
                        action='store_true')
    parser.add_argument('--full_bytes', help='display full byte arrays',
                        action='store_true')
    parser.add_argument('--no_colors', help='disable colors in output',
                        action='store_true')
    parser.add_argument('--no_headers', help='skip information about headers',
                        action='store_true')
    parser.add_argument('--no_modules', help='skip information about modules',
                        action='store_true')
    parser.add_argument('file_path', help='path to fw binary file to parse')
    parsed_args = parser.parse_args()

    return parsed_args

# Helper Functions

def change_color(color):
    """ Prints escape code to change text color
    """
    color_code = {'red':91, 'green':92, 'yellow':93, 'blue':94,
                  'magenta':95, 'cyan':96, 'white':98, 'none':0}
    return '\033[{}m'.format(color_code[color])

def uint_to_string(uint, both=False):
    """ Prints uint in readable form
    """
    if both:
        return hex(uint) + ' (' + repr(uint) + ')'
    return hex(uint)

def date_to_string(date):
    """ Prints BCD date in readable form
    """
    return date[2:6]+'/'+date[6:8]+'/'+date[8:10]

def chararr_to_string(chararr, max_len):
    """ Prints array of characters (null terminated or till max_len)
        in readable form
    """
    out = ''
    for i in range(0, max_len):
        if chararr[i] == 0:
            return out
        out += '{:c}'.format(chararr[i])
    return out

def mod_type_to_string(mod_type):
    """ Prints module type in readable form
    """
    out = '('
    # type
    if (mod_type & 0xf) == 0:
        out += ' builtin'
    elif (mod_type & 0xf) == 1:
        out += ' loadable'
    # Module that may be instantiated by fw on startup
    if ((mod_type >> 4) & 0x1) == 1:
        out += ' auto_start'
    # Module designed to run with low latency scheduler
    if ((mod_type >> 5) & 0x1) == 1:
        out += ' LL'
    # Module designed to run with edf scheduler
    if ((mod_type >> 6) & 0x1) == 1:
        out += ' DP'
    out += ' )'
    return out

def seg_flags_to_string(flags):
    """ Prints module segment flags in readable form
    """
    out = '('
    if flags & 0x1 == 0x1:
        out = out + ' contents'
    if flags & 0x2 == 0x2:
        out = out + ' alloc'
    if flags & 0x4 == 0x4:
        out = out + ' load'
    if flags & 0x8 == 0x8:
        out = out + ' readonly'
    if flags & 0x10 == 0x10:
        out = out + ' code'
    if flags & 0x20 == 0x20:
        out = out + ' data'
    out = out + ' type=' + repr((flags>>8)&0xf)
    out = out + ' pages=' + repr((flags>>16)&0xffff)
    out = out + ' )'
    return out

# Parsers

def parse_cse_manifest(reader):
    """ Parses CSE manifest form fw binary
    """
    reader.info('Looking for CSE Manifest')
    cse_mft = CseManifest(reader.get_offset())

    # Try to detect signature first
    sig = reader.read_string(4)
    if sig != '$CPD':
        reader.error('CSE Manifest NOT found ' + sig + ')', -4)
        sys.exit(1)
    reader.info('CSE Manifest (' + sig + ')', -4)

    # Read the header
    hdr = Component('cse_mft_hdr', 'Header', reader.get_offset())
    cse_mft.add_comp(hdr)
    hdr.add_a(Astring('sig', sig))
    # read number of entries
    nb_entries = reader.read_dw()
    reader.info('# of entries {}'.format(nb_entries))
    hdr.add_a(Adec('nb_entries', nb_entries))
    # read version (1byte for header ver and 1 byte for entry ver)
    ver = reader.read_w()
    hdr.add_a(Ahex('header_version', ver))
    header_length = reader.read_b()
    hdr.add_a(Ahex('header_length', header_length))
    hdr.add_a(Ahex('checksum', reader.read_b()))
    hdr.add_a(Astring('partition_name', reader.read_string(4)))

    reader.set_offset(cse_mft.file_offset + header_length)
    # Read entries
    nb_index = 0
    while nb_index < nb_entries:
        reader.info('Looking for CSE Manifest entry')
        entry_name = reader.read_string(12)
        entry_offset = reader.read_dw()
        entry_length = reader.read_dw()
        # reserved field
        reader.read_dw()

        hdr_entry = Component('cse_hdr_entry', 'Entry', reader.get_offset())
        hdr_entry.add_a(Astring('entry_name', entry_name))
        hdr_entry.add_a(Ahex('entry_offset', entry_offset))
        hdr_entry.add_a(Ahex('entry_length', entry_length))
        hdr.add_comp(hdr_entry)

        reader.info('CSE Entry name {} length {}'.format(entry_name,
                    entry_length))

        nb_index += 1
        if '.man' in entry_name:
            entry = CssManifest(entry_name,
                                reader.ext_mft_length + entry_offset)
            cur_off = reader.set_offset(reader.ext_mft_length + entry_offset)
            parse_css_manifest(entry, reader,
                               reader.ext_mft_length + entry_offset + entry_length)
            reader.set_offset(cur_off)
        elif '.met' in entry_name:
            cur_off = reader.set_offset(reader.ext_mft_length + entry_offset)
            entry = parse_mft_extension(reader, 0)
            entry.name = '{} ({})'.format(entry_name, entry.name)
            reader.set_offset(cur_off)
        else:
            continue
        cse_mft.add_comp(entry)

    return cse_mft

def parse_css_manifest(css_mft, reader, limit):
    """ Parses CSS manifest from fw binary
    """
    reader.info('Parsing CSS Manifest')
    ver, = struct.unpack('I', reader.get_data(0, 4))
    if ver == 4:
        reader.info('CSS Manifest type 4')
        return parse_css_manifest_4(css_mft, reader, limit)

    reader.error('CSS Manifest NOT found or NOT recognized!')
    sys.exit(1)

def parse_css_manifest_4(css_mft, reader, size_limit):
    """ Parses CSS manifest type 4 from fw binary
    """

    reader.info('Parsing CSS Manifest type 4')
    # CSS Header
    hdr = Component('css_mft_hdr', 'Header', reader.get_offset())
    css_mft.add_comp(hdr)

    hdr.add_a(Auint('type', reader.read_dw()))
    header_len_dw = reader.read_dw()
    hdr.add_a(Auint('header_len_dw', header_len_dw))
    hdr.add_a(Auint('header_version', reader.read_dw()))
    hdr.add_a(Auint('reserved0', reader.read_dw(), 'red'))
    hdr.add_a(Ahex('mod_vendor', reader.read_dw()))
    hdr.add_a(Adate('date', hex(reader.read_dw())))
    size = reader.read_dw()
    hdr.add_a(Auint('size', size))
    hdr.add_a(Astring('header_id', reader.read_string(4)))
    hdr.add_a(Auint('padding', reader.read_dw()))
    hdr.add_a(Aversion('fw_version', reader.read_w(), reader.read_w(),
                       reader.read_w(), reader.read_w()))
    hdr.add_a(Auint('svn', reader.read_dw()))
    reader.read_bytes(18*4)
    modulus_size = reader.read_dw()
    hdr.add_a(Adec('modulus_size', modulus_size))
    exponent_size = reader.read_dw()
    hdr.add_a(Adec('exponent_size', exponent_size))
    modulus = reader.read_bytes(modulus_size * 4)
    hdr.add_a(Amodulus('modulus', modulus, KNOWN_KEYS.get(modulus, 'Other')))
    hdr.add_a(Abytes('exponent', reader.read_bytes(exponent_size * 4)))
    hdr.add_a(Abytes('signature', reader.read_bytes(modulus_size * 4)))

    # Move right after the header
    reader.set_offset(css_mft.file_offset + header_len_dw*4)

    # Anything packed here is
    #   either an 'Extension' beginning with
    #     dw0 - extension type
    #     dw1 - extension length (in bytes)
    #   that could be parsed if extension type is recognized
    #
    #   or series of 0xffffffff that should be skipped
    reader.info('Parsing CSS Manifest extensions end 0x{:x}'.format(size_limit))
    ext_idx = 0
    while reader.get_offset() < size_limit:
        ext_type = reader.read_dw()
        reader.info('Reading extension type 0x{:x}'.format(ext_type))
        if ext_type == 0xffffffff:
            continue
        reader.set_offset(reader.get_offset() - 4)
        css_mft.add_comp(parse_mft_extension(reader, ext_idx))
        ext_idx += 1

    return css_mft

def parse_mft_extension(reader, ext_id):
    """ Parses mft extension from fw binary
    """
    ext_type = reader.read_dw()
    ext_len = reader.read_dw()
    if ext_type == 15:
        begin_off = reader.get_offset()
        ext = PlatFwAuthExtension(ext_id, reader.get_offset()-8)
        ext.add_a(Astring('name', reader.read_string(4)))
        ext.add_a(Auint('vcn', reader.read_dw()))
        ext.add_a(Abytes('bitmap', reader.read_bytes(16), 'red'))
        ext.add_a(Auint('svn', reader.read_dw()))
        read_len = reader.get_offset() - begin_off
        reader.ff_data(ext_len - read_len)
    else:
        ext = MftExtension(ext_id, 'Other Extension', reader.get_offset()-8)
        reader.ff_data(ext_len-8)
    ext.add_a(Auint('type', ext_type))
    ext.add_a(Auint('length', ext_len))
    return ext

def parse_fw_bin(path, verbose):
    """ Parses fw binary
    """
    reader = BinReader(path, verbose)

    parsed_bin = FwBin()
    parsed_bin.add_a(Astring('file_name', reader.file_name))
    parsed_bin.add_a(Auint('file_size', reader.file_size))
    parsed_bin.add_comp(parse_cse_manifest(reader))
    reader.set_offset(reader.ext_mft_length + 0x2000)

    reader.info('Parsing finished', show_offset = False)
    return parsed_bin

class BinReader():
    """ fw binary reader
    """
    def __init__(self, path, verbose):
        self.verbose = verbose
        self.cur_offset = 0
        self.ext_mft_length = 0
        self.info('Reading IPU fw image ' + path, show_offset=False)
        self.file_name = path
        # read the content
        self.data = open(path, 'rb').read()
        self.file_size = len(self.data)
        self.info('File size ' + uint_to_string(self.file_size, True),
                  show_offset=False)

    def get_offset(self):
        """ Retrieve the offset, the reader is at
        """
        return self.cur_offset

    def ff_data(self, delta_offset):
        """ Forwards the read pointer by specified number of bytes
        """
        self.cur_offset += delta_offset

    def set_offset(self, offset):
        """ Set current reader offset
        """
        old_offset = self.cur_offset
        self.cur_offset = offset
        return old_offset

    def get_data(self, beg, length):
        """ Retrieves the data from beg to beg+length.
            This one is good to peek the data w/o advancing the read pointer
        """
        return self.data[self.cur_offset +beg : self.cur_offset +beg +length]

    def read_bytes(self, count):
        """ Reads the specified number of bytes from the stream
        """
        bts = self.get_data(0, count)
        self.ff_data(count)
        return bts

    def read_dw(self):
        """ Reads a dword from the stream
        """
        dword, = struct.unpack('I', self.get_data(0, 4))
        self.ff_data(4)
        return dword

    def read_w(self):
        """ Reads a word from the stream
        """
        word, = struct.unpack('H', self.get_data(0, 2))
        self.ff_data(2)
        return word

    def read_b(self):
        """ Reads a byte from the stream
        """
        byte, = struct.unpack('B', self.get_data(0, 1))
        self.ff_data(1)
        return byte

    def read_string(self, size_in_file):
        """ Reads a string from the stream, potentially padded with zeroes
        """
        return self.read_bytes(size_in_file).decode().rstrip('\0')

    def read_uuid(self):
        """ Reads a UUID from the stream and returns as string
        """
        out = '{:08x}'.format(self.read_dw())
        out += '-'+'{:04x}'.format(self.read_w())
        out += '-'+'{:04x}'.format(self.read_w())
        out += '-'+'{:02x}'.format(self.read_b()) + \
               '{:02x}'.format(self.read_b()) + '-'
        for _ in range(0, 6):
            out += '{:02x}'.format(self.read_b())
        return out

    def offset_to_string(self, delta=0):
        """ Retrieves readable representation of the current offset value
        """
        return uint_to_string(self.cur_offset+delta)

    def info(self, loginfo, off_delta=0, verb_info=True, show_offset=True):
        """ Prints 'info' log to the output, respects verbose mode
        """
        if verb_info and not self.verbose:
            return
        if show_offset:
            print(self.offset_to_string(off_delta) + '\t' + loginfo)
        else:
            print(loginfo)

    def error(self, logerror, off_delta=0):
        """ Prints 'error' log to the output
        """
        print(self.offset_to_string(off_delta) + '\terror: ' + logerror)

# Data Model

class Attribute():
    """ Attribute: base class with global formatting options
    """
    no_colors = False
    full_bytes = True

class Auint(Attribute):
    """ Attribute : unsigned integer
    """
    def __init__(self, name, val, color='none'):
        self.name = name
        self.val = val
        self.color = color

    def __str__(self):
        if Attribute.no_colors:
            return uint_to_string(self.val)
        return '{}{}{}'.format(change_color(self.color),
                               uint_to_string(self.val),
                               change_color('none'))

class Ahex(Attribute):
    """ Attribute : unsigned integer printed as hex
    """
    def __init__(self, name, val, color='none'):
        self.name = name
        self.val = val
        self.color = color

    def __str__(self):
        if Attribute.no_colors:
            return hex(self.val)
        return '{}{}{}'.format(change_color(self.color), hex(self.val),
                               change_color('none'))

class Adec(Attribute):
    """ Attribute: integer printed as dec
    """
    def __init__(self, name, val):
        self.name = name
        self.val = val

    def __str__(self):
        return repr(self.val)

class Abytes(Attribute):
    """ Attribute: array of bytes
    """
    def __init__(self, name, val, color='none'):
        self.name = name
        self.val = val
        self.color = color

    def __str__(self):
        length = len(self.val)
        if Attribute.no_colors:
            out = ''
        else:
            out = '{}'.format(change_color(self.color))
        if Attribute.full_bytes or length <= 16:
            out += ' '.join(['{:02x}'.format(b) for b in self.val])
        else:
            out += ' '.join('{:02x}'.format(b) for b in self.val[:8])
            out += ' ... '
            out += ' '.join('{:02x}'.format(b) for b in self.val[length-8:length])
        if not Attribute.no_colors:
            out += '{}'.format(change_color('none'))
        return out

class Adate(Attribute):
    """ Attribute: Date in BCD format
    """
    def __init__(self, name, val):
        self.name = name
        self.val = val

    def __str__(self):
        return date_to_string(self.val)

class Astring(Attribute):
    """ Attribute: String
    """
    def __init__(self, name, val):
        self.name = name
        self.val = val

    def __str__(self):
        return self.val

class Aversion(Attribute):
    """ Attribute: version
    """
    def __init__(self, name, major, minor, hotfix, build):
        self.name = name
        self.val = '{:d}.{:d}.{:d}.{:d}'.format(major, minor, hotfix, build)

    def __str__(self):
        return self.val

class Amodulus(Abytes):
    """ Attribute: modulus from RSA public key
    """
    def __init__(self, name, val, val_type):
        super().__init__(name, val)
        self.val_type = val_type

    def __str__(self):
        out = super().__str__()
        if not Attribute.full_bytes:
            if Attribute.no_colors:
                out += ' ({})'.format(self.val_type)
            else:
                out += ' {}({}){}'.format(change_color('red'), self.val_type,
                                          change_color('none'))
        return out

class Component():
    """ A component of fw binary
    """
    def __init__(self, uid, name, file_offset):
        self.uid = uid
        self.name = name
        self.file_offset = file_offset
        self.attribs = []
        self.adir = {}
        self.max_attr_name_len = 0
        self.components = []
        self.cdir = {}

    def add_a(self, attrib):
        """ Adds an attribute
        """
        self.max_attr_name_len = max(self.max_attr_name_len,
                                     len(attrib.name))
        self.attribs.append(attrib)
        self.adir[attrib.name] = attrib

    def add_comp(self, comp):
        """ Adds a nested component
        """
        self.components.append(comp)
        self.cdir[comp.uid] = comp

    def get_comp(self, comp_uid):
        """ Retrieves a nested component by id
        """
        for comp in self.components:
            if comp.uid == comp_uid:
                return comp
        return None

    def dump_info(self, pref, comp_filter):
        """ Prints out the content (name, all attributes, and nested comps)
        """
        print(pref + self.name)
        for attrib in self.attribs:
            print("{:}  {:<{:}} {:}".format(pref, attrib.name,
                                            self.max_attr_name_len, attrib))
        self.dump_comp_info(pref, comp_filter)

    def dump_attrib_info(self, pref, attr_name):
        """ Prints out a single attribute
        """
        attrib = self.adir[attr_name]
        print("{:}  {:<{:}} {:}".format(pref, attrib.name,
                                        self.max_attr_name_len, attrib))

    def dump_comp_info(self, pref, comp_filter=''):
        """ Prints out all nested components (filtered by name set to 'filter')
        """
        for comp in self.components:
            if comp.name in comp_filter:
                continue
            print()
            comp.dump_info(pref + '  ', comp_filter)

    def add_comp_to_mem_map(self, mem_map):
        for comp in self.components:
            comp.add_comp_to_mem_map(mem_map)

class ExtendedManifestAE1(Component):
    """ Extended manifest
    """
    def __init__(self):
        super(ExtendedManifestAE1, self).__init__('ext_mft',
                                               'Extended Manifest', 0)

    def dump_info(self, pref, comp_filter):
        hdr = self.cdir['ext_mft_hdr']
        if hdr.adir['length'].val == 0:
            return
        out = '{}{}'.format(pref, self.name)
        out += ' ver {}'.format(hdr.adir['ver'])
        out += ' entries {}'.format(hdr.adir['entries'])
        print(out)
        self.dump_comp_info(pref, comp_filter + ['Header'])

class ExtendedManifestXMan(Component):
    """ Extended manifest
    """
    def __init__(self):
        super(ExtendedManifestXMan, self).__init__('ext_mft',
                                               'Extended Manifest', 0)

    def dump_info(self, pref, comp_filter):
        hdr = self.cdir['ext_mft_hdr']
        if hdr.adir['length'].val == 0:
            return
        out = '{}{}'.format(pref, self.name)
        out += ' ver {}'.format(hdr.adir['ver'])
        out += ' length {}'.format(hdr.adir['length'].val)
        print(out)
        self.dump_comp_info(pref, comp_filter + ['Header'])

class CseManifest(Component):
    """ CSE Manifest
    """
    def __init__(self, offset):
        super(CseManifest, self).__init__('cse_mft', 'CSE Manifest', offset)

    def dump_info(self, pref, comp_filter):
        hdr = self.cdir['cse_mft_hdr']
        print('{}{} ver {} checksum {} partition name {}'.
              format(pref,
                     self.name, hdr.adir['header_version'],
                     hdr.adir['checksum'], hdr.adir['partition_name']))
        self.dump_comp_info(pref, comp_filter + ['Header'])

class CssManifest(Component):
    """ CSS Manifest
    """
    def __init__(self, name, offset):
        super(CssManifest, self).__init__('css_mft', name, offset)

    def dump_info(self, pref, comp_filter):
        hdr = self.cdir['css_mft_hdr']
        out = '{}{} (CSS Manifest)'.format(pref, self.name)
        out += ' type {}'.format(hdr.adir['type'])
        out += ' ver {}'.format(hdr.adir['header_version'])
        out += ' date {}'.format(hdr.adir['date'])
        print(out)
        print('{}  Rsvd0 {}'.
              format(pref, hdr.adir['reserved0']))
        print('{}  Modulus size (dwords) {}'.
              format(pref, hdr.adir['modulus_size']))
        print('{}    {}'.format(pref, hdr.adir['modulus']))
        print('{}  Exponent size (dwords) {}'.
              format(pref,
                     hdr.adir['exponent_size']))
        print('{}    {}'.format(pref, hdr.adir['exponent']))
        print('{}  Signature'.format(pref))
        print('{}    {}'.format(pref, hdr.adir['signature']))
        # super().dump_info(pref)
        self.dump_comp_info(pref, comp_filter + ['Header'])

class MftExtension(Component):
    """ Manifest Extension
    """
    def __init__(self, ext_id, name, offset):
        super(MftExtension, self).__init__('mft_ext'+repr(ext_id), name,
                                           offset)

    def dump_info(self, pref, comp_filter):
        print('{}{} type {} length {}'.
              format(pref, self.name,
                     self.adir['type'], self.adir['length']))

class PlatFwAuthExtension(MftExtension):
    """ Platform FW Auth Extension
    """
    def __init__(self, ext_id, offset):
        super(PlatFwAuthExtension,
              self).__init__(ext_id, 'Plat Fw Auth Extension', offset)

    def dump_info(self, pref, comp_filter):
        out = '{}{}'.format(pref, self.name)
        out += ' name {}'.format(self.adir['name'])
        out += ' vcn {}'.format(self.adir['vcn'])
        out += ' bitmap {}'.format(self.adir['bitmap'])
        out += ' svn {}'.format(self.adir['svn'])
        print(out)

class FwBin(Component):
    """ Parsed fw binary
    """
    def __init__(self):
        super(FwBin, self).__init__('bin', 'FW Binary', 0)

    def dump_info(self, pref, comp_filter):
        """ Print out the content
        """
        print('FW Binary {} size {}'.format(
            self.adir['file_name'], self.adir['file_size']))
        self.dump_comp_info(pref, comp_filter)

def main(args):
    """ main function
    """
    if sys.stdout.isatty():
        Attribute.no_colors = args.no_colors
    else:
        Attribute.no_colors = True

    Attribute.full_bytes = args.full_bytes

    fw_bin = parse_fw_bin(args.file_path, args.verbose)

    comp_filter = []
    if args.headers or args.no_modules:
        comp_filter.append('Module Entry')
    if args.no_headers:
        comp_filter.append('CSE Manifest')
    fw_bin.dump_info('', comp_filter)

if __name__ == "__main__":
    ARGS = parse_params()
    main(ARGS)
