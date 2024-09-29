# ipu6-camera-bins

This repository supports MIPI cameras through the IPU6 on Intel Tiger Lake, Alder Lake, Raptor Lake and Meteor Lake platforms.
There are 4 repositories that provide the complete setup:

- https://github.com/intel/ipu6-drivers - kernel drivers for the IPU and sensors
- https://github.com/intel/ipu6-camera-bins - IPU firmware and proprietary image processing libraries
- https://github.com/intel/ipu6-camera-hal - HAL for processing of images in userspace
- https://github.com/intel/icamerasrc/tree/icamerasrc_slim_api (branch:icamerasrc_slim_api) - Gstreamer src plugin

## Content of this repository:
- IPU6 firmware binaries
- Library binary dependencies for ipu6-camera-hal
- Headerfiles for those libraries

## Deployment
ipu6-camera-bins should be copied to build server and target
```
# Runtime files
mkdir -p /lib/firmware/intel/ipu
cp -r ipu6-camera-bins/lib/firmware/intel/ipu/*.bin /lib/firmware/intel/ipu
# For developers using engineer samples, try use unsigned FW if authenticate fail:
# cp -r ipu6-camera-bins/lib/firmware/intel/ipu/unsigned/*.bin /lib/firmware/intel/ipu
cp -P ipu6-camera-bins/lib/lib* /usr/lib/
# Development files
mkdir -p /usr/include/ipu6 /usr/lib/pkgconfig
cp -r ipu6-camera-bins/include/* /usr/include/
cp -r ipu6-camera-bins/lib/pkgconfig/* /usr/lib/pkgconfig/
```
