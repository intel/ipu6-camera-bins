##  Copy ipu6 binary to build environment
1. cp -rf ipu6_binary/lib/* /usr/lib
2. cp -rf ipu6_binary/include/* /usr/include/
3. cp -rf ipu6_binary/firmware/ipu6ep_fw.bin /lib/firmware
4. cp -rf ipu6_binary/aiqb/AR0234_TGL_10bits.aiqb /usr/share/defaults/etc/camera/
