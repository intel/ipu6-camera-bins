# ipu6-camera-bins

This repository supports MIPI cameras through the IPU6EP on Intel Alderlake platforms. There are 4 repositories that provide the complete setup:

* https://github.com/intel/ipu6-drivers (branch:ccg_plat_adlp) - kernel drivers for the IPU and sensors
* https://github.com/intel/ipu6-camera-hal (branch:ccg_plat_adlp) - HAL for processing of images in userspace
* https://github.com/intel/ipu6-camera-bins (branch:ccg_plat_adlp) - IPU firmware and proprietary image processing libraries
* https://github.com/intel/icamerasrc (branch:icamerasrc_slim_api) - Gstreamer src plugin


## Content of this repository:
* IPU6EP firmware
* Library binary dependencies for IPU6EP HAL
* Headerfiles for those libraries

## Deployment
ipu6-camera-bins should be copied to build server and target
```
cp -r ipu6-camera-bins/include/* /usr/include/
cp -r ipu6-camera-bins/lib/* /usr/lib/
```
