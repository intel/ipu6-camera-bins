# ipu6-camera-bins

This repository supports MIPI cameras through the IPU6SE on Intel Jasper Lake platforms. There are 4 repositories that provide the complete setup:

* https://github.com/intel/ipu6-drivers (branch:jsl_penguin_peak) - kernel drivers for the IPU and sensors
* https://github.com/intel/ipu6-camera-hal (branch:jsl_penguin_peak) - HAL for processing of images in userspace
* https://github.com/intel/ipu6-camera-bins (branch:jsl_penguin_peak) - IPU firmware and proprietary image processing libraries
* https://github.com/intel/icamerasrc (branch:icamerasrc_slim_api) - Gstreamer src plugin

## Content of this repository:
* IPU6SE firmware
* Library binary dependencies for IPU6SE HAL
* Headerfiles for those libraries

## Deployment
ipu6-camera-bins should be copied to build server and target
```
cp -rP ipu6-camera-bins/include/* /usr/include/
cp -rP ipu6-camera-bins/lib/* /usr/lib/
```
