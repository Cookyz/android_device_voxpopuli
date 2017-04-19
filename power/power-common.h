/*
 * Copyright (C) 2017  Joshua Choo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **********************************************************************
 *
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * *    * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#define NODE_MAX (64)

#define SCALING_GOVERNOR_PATH "/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"
#define DCVS_CPU0_SLACK_MAX_NODE "/sys/module/msm_dcvs/cores/cpu0/slack_time_max_us"
#define DCVS_CPU0_SLACK_MIN_NODE "/sys/module/msm_dcvs/cores/cpu0/slack_time_min_us"
#define MPDECISION_SLACK_MAX_NODE "/sys/module/msm_mpdecision/slack_time_max_us"
#define MPDECISION_SLACK_MIN_NODE "/sys/module/msm_mpdecision/slack_time_min_us"
#define SCALING_MIN_FREQ "/sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq"
#define ONDEMAND_GOVERNOR "ondemand"
#define INTERACTIVE_GOVERNOR "interactive"
#define MSMDCVS_GOVERNOR "msm-dcvs"
#define ALUCARDSCHED_GOVERNOR "alucardsched"
#define DARKNESSSCHED_GOVERNOR "darknesssched"
#define SCHED_GOVERNOR "sched"
#define SCHEDUTIL_GOVERNOR "schedutil"
#define PWRUTIL_GOVERNOR "pwrutil"

#define ENABLE_INTERACTION_BOOST_PATH		"/dev/power/enable_interaction_boost"
#define FLING_MIN_BOOST_DURATION_PATH 		"/dev/power/fling_min_boost_duration"
#define FLING_MAX_BOOST_DURATION_PATH 		"/dev/power/fling_max_boost_duration"
#define FLING_BOOST_TOPAPP_PATH 		"/dev/power/fling_boost_topapp"
#define FLING_MIN_FREQ_BIG_PATH 		"/dev/power/fling_min_freq_big"
#define FLING_MIN_FREQ_LITTLE_PATH 		"/dev/power/fling_min_freq_little"
#define TOUCH_BOOST_DURATION_PATH 		"/dev/power/touch_boost_duration"
#define TOUCH_BOOST_TOPAPP_PATH 		"/dev/power/touch_boost_topapp"
#define TOUCH_MIN_FREQ_BIG_PATH 		"/dev/power/touch_min_freq_big"
#define TOUCH_MIN_FREQ_LITTLE_PATH 		"/dev/power/touch_min_freq_little"

#define HINT_HANDLED (0)
#define HINT_NONE (-1)

enum CPU_GOV_CHECK {
    CPU0 = 0,
    CPU1 = 1,
    CPU2 = 2,
    CPU3 = 3
};

const char * eas_governors[];
int is_eas_governor(const char *governor);
void get_int(const char* file_path, int* value, int fallback_value);
