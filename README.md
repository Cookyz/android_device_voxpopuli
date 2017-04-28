# Vox Populi Power HAL
## Introduction
Vox Populi is a Power HAL based on the Marlin Power HAL, and made specifically for EAS-supported ROMs. By default, EAS governors/kernels do not have any form of touchboost yet. The Power HAL is needed to provide EAS ROMs with boosting for app launches and touch/fling events, thereby increasing performance and giving users a very smooth experience. It does this by receiving hints from the Android OS regarding events (e.g. touch and app launches), and it then instructs the kernel via the perfd blob to alter the kernel's parameters (e.g. frequency) to specified values. The Power HAL is the very reason for the Google Pixel's smoothness. Vox Populi Power HAL supports all custom EAS governors and offers users the ability to tweak boosting parameters in **/dev/voxpopuli**.

## Credits
I would like to acknowledge [@myfluxi](https://github.com/myfluxi) for providing the first hints to this work.

Great thanks and much appreciation to [@RenderBroken](https://github.com/RenderBroken) for partnering with me to bring full EAS support to the OP3. We spent countless hours tossing ideas, building, testing, debugging, and constantly optimising EAS for the kernel and VertexOS ROM. We finally did it!

## Supported device platforms (IMPORTANT!)
* MSM8996 (and its variants)

## GNU GPLv3 compliance
Vox Populi is licensed under the GNU GPLv3.
You are permitted to do the following:
* Commercial use
* Modification
* Distribution
* Patent use
* Private use

You must abide by the following conditions:
* License and copyright notice: You must include a copy of the License and copyright notices found in the repository and source files.
* State changes: You may do this through your commit history.
* Disclose source: Source code must be made available when distributing software with Vox Populi commits/work. 
* Same License: Modifications to Vox Populi must be released under the same license (GNU GPLv3) when distributing.

## Getting started with EAS integration for ROM developers
The following steps are the bare minimum to get EAS working on your device.
1. Ensure that you have a kernel with all the necessary EAS commits. You may refer to [@RenderBroken's](https://github.com/RenderBroken) fantastic [LineageOS-based kernel with EAS changes](https://github.com/EAS-Project/msm8996-eas) for an idea of how to achieve an EAS kernel.
2. Add the following line in your device tree's **BoardConfig.mk**:
```
ENABLE_CPUSETS := true
ENABLE_SCHEDBOOST := true
```
*Note: ENABLE_SCHEDBOOST may not be needed in future if you have merged the bleeding-edge system/core commits, but there's no harm in adding it if you're unsure.*

## Getting started with Vox Populi for ROM developers
The following steps will provide a powerful touchboost mechanism to complement your EAS system.
1. Clone the repo to **device/voxpopuli** in your build's root directory.
2. Add/change the following in your device tree's **BoardConfig.mk**:
```
TARGET_POWERHAL_VARIANT := voxpopuli
TARGET_USES_INTERACTION_BOOST := true
-include device/voxpopuli/sepolicy/sepolicy.mk
```
3. Ensure the following exists in your device tree's **device.mk**:
```
PRODUCT_PACKAGES += \
    power.msm8996
```
4. Create the Vox Populi tunables at initialisation in one of your device tree's init.*.rc files (**init.qcom.power.rc** is recommended):
```
on init
    # Create Power HAL tunables
    mkdir /dev/voxpopuli 0555 system system

on boot
    # Set Power HAL tunables
    write /dev/voxpopuli/enable_interaction_boost   1
    write /dev/voxpopuli/fling_min_boost_duration   200
    write /dev/voxpopuli/fling_max_boost_duration   2500
    write /dev/voxpopuli/fling_boost_topapp         10
    write /dev/voxpopuli/fling_min_freq_big         1113
    write /dev/voxpopuli/fling_min_freq_little      1113
    write /dev/voxpopuli/touch_boost_duration       200
    write /dev/voxpopuli/touch_boost_topapp         5
    write /dev/voxpopuli/touch_min_freq_big         1036
    write /dev/voxpopuli/touch_min_freq_little      1036
    chmod 0644 /dev/voxpopuli/enable_interaction_boost
    chmod 0644 /dev/voxpopuli/fling_min_boost_duration
    chmod 0644 /dev/voxpopuli/fling_max_boost_duration
    chmod 0644 /dev/voxpopuli/fling_boost_topapp      
    chmod 0644 /dev/voxpopuli/fling_min_freq_big      
    chmod 0644 /dev/voxpopuli/fling_min_freq_little   
    chmod 0644 /dev/voxpopuli/touch_boost_duration    
    chmod 0644 /dev/voxpopuli/touch_boost_topapp      
    chmod 0644 /dev/voxpopuli/touch_min_freq_big      
    chmod 0644 /dev/voxpopuli/touch_min_freq_little   
    chown system system /dev/voxpopuli/enable_interaction_boost
    chown system system /dev/voxpopuli/fling_min_boost_duration
    chown system system /dev/voxpopuli/fling_max_boost_duration
    chown system system /dev/voxpopuli/fling_boost_topapp      
    chown system system /dev/voxpopuli/fling_min_freq_big      
    chown system system /dev/voxpopuli/fling_min_freq_little   
    chown system system /dev/voxpopuli/touch_boost_duration    
    chown system system /dev/voxpopuli/touch_boost_topapp      
    chown system system /dev/voxpopuli/touch_min_freq_big      
    chown system system /dev/voxpopuli/touch_min_freq_little
```
*Note: Feel free to change the default values of the tunables that you created above.*

5. Replace the following perfd blobs from your proprietary vendor repo with the latest **EAS-compatible** Marlin perfd blobs ([example commit](https://github.com/VertexOS-Devices/proprietary_vendor_oneplus/commit/6ef2f89e8743ef514156b40513c8b442fe015f7b)):
- perfd
- libqti-perfd-client.so (lib)
- libqti-perfd-client.so (lib64)
6. Add the following sepolicies for perfd as shown in [this commit](https://github.com/VertexOS-Devices/android_device_oneplus_oneplus3/commit/967e81ad7de888c6bcec4661fde362465b4171fa).
7. Please maintain the original commit history and authorship, and **do not kang my work** :p
8. Please provide clear credits to me, [@joshuous](https://github.com/joshuous/), if you're using Vox Populi.

## Getting started for Kernel Developers (coming soon...)
Porting EAS to any device with a flashable...
