# ipu6-camera-bins

This repository supports MIPI cameras through the IPU6EP on Intel Alder Lake, Raptor Lake and Meteor Lake platforms. There are 4 repositories that provide the complete setup:

* https://github.com/intel/ipu6-drivers (branch:iotg_ipu6) - kernel drivers for the IPU and sensors
* https://github.com/intel/ipu6-camera-hal (branch:iotg_ipu6) - HAL for processing of images in userspace
* https://github.com/intel/ipu6-camera-bins (branch:iotg_ipu6) - IPU firmware and proprietary image processing libraries
* https://github.com/intel/icamerasrc (branch:icamerasrc_slim_api) - Gstreamer src plugin


## Content of this repository:
* IPU6EP firmware
* Library binary dependencies for IPU6EP HAL
* Headerfiles for those libraries

## Deployment
ipu6-camera-bins should be copied to build server and target
```
# For ADL/RPL, IPU_VER=ipu6ep
# For MTL, IPU_VER=ipu6epmtl
cp -r ipu6-camera-bins/<IPU_VER>/include/* /usr/include/
cp -r ipu6-camera-bins/<IPU_VER>/lib/* /usr/lib/
```
