# Vox Populi Power HAL
## Introduction
Vox Populi is a Power HAL based on the Marlin Power HAL, and made specifically for EAS-supported ROMs. It provides EAS ROMs with boosting for app launches and touch/fling events, thereby providing increased performance and giving users a very smooth experience. It supports several custom EAS governors and offers users the ability to tweak boosting parameters in **/dev/power**.

## Credits
I would like to acknowledge [@myfluxi](https://github.com/myfluxi) for providing the first hints to this work.

Great thanks and much appreciation to [@RenderBroken](https://github.com/RenderBroken) for partnering with me to bring full EAS support to the OP3. We spent countless hours tossing ideas, building, testing, debugging, and constantly optimising EAS for the kernel and VertexOS ROM. We finally did it!

## Supported device platforms
* MSM8996

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

## Getting started for ROM developers
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
    mkdir /dev/power 0555 system system

on boot
    # Set Power HAL tunables
    write /dev/power/enable_interaction_boost   1
    write /dev/power/fling_min_boost_duration   200
    write /dev/power/fling_max_boost_duration   2500
    write /dev/power/fling_boost_topapp         10
    write /dev/power/fling_min_freq_big         1113
    write /dev/power/fling_min_freq_little      1113
    write /dev/power/touch_boost_duration       200
    write /dev/power/touch_boost_topapp         5
    write /dev/power/touch_min_freq_big         1036
    write /dev/power/touch_min_freq_little      1036
    chmod 0644 /dev/power/enable_interaction_boost
    chmod 0644 /dev/power/fling_min_boost_duration
    chmod 0644 /dev/power/fling_max_boost_duration
    chmod 0644 /dev/power/fling_boost_topapp      
    chmod 0644 /dev/power/fling_min_freq_big      
    chmod 0644 /dev/power/fling_min_freq_little   
    chmod 0644 /dev/power/touch_boost_duration    
    chmod 0644 /dev/power/touch_boost_topapp      
    chmod 0644 /dev/power/touch_min_freq_big      
    chmod 0644 /dev/power/touch_min_freq_little   
    chown system system /dev/power/enable_interaction_boost
    chown system system /dev/power/fling_min_boost_duration
    chown system system /dev/power/fling_max_boost_duration
    chown system system /dev/power/fling_boost_topapp      
    chown system system /dev/power/fling_min_freq_big      
    chown system system /dev/power/fling_min_freq_little   
    chown system system /dev/power/touch_boost_duration    
    chown system system /dev/power/touch_boost_topapp      
    chown system system /dev/power/touch_min_freq_big      
    chown system system /dev/power/touch_min_freq_little
```
5. Feel free to change the default values of the tunables that you created above.
6. Replace the perfd binary from your proprietary vendor repo with the **EAS-compatible** Marlin perfd. [Example commit here](https://github.com/myfluxi/proprietary_vendor_oneplus/commit/cdd71f9dfc4c23afd4d550f4d20b1f52835dd7c1).
7. Please maintain the original commit history and authorship, and **do not kang my work** :p
8. Please provide clear credits to me, [@joshuous](https://github.com/joshuous/), if you're using Vox Populi.
