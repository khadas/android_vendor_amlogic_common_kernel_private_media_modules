/*
 * drivers/amlogic/amports/arch/secprot.h
 *
 * Copyright (C) 2017 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
*/

#ifndef __SECPROT_H_
#define __SECPROT_H_

#define DMC_DEV_TYPE_NON_SECURE        0
#define DMC_DEV_TYPE_SECURE            1

#define DMC_DEV_ID_GPU                 1
#define DMC_DEV_ID_HEVC                4
#define DMC_DEV_ID_PARSER              7
#define DMC_DEV_ID_VPU                 8
#define DMC_DEV_ID_VDEC                13
#define DMC_DEV_ID_HCODEC              14
#define DMC_DEV_ID_GE2D                15

#define OPTEE_SMC_CONFIG_DEVICE_SECURE 0xb200000e

/*#define __asmeq(x, y)  ".ifnc " x "," y " ; .err ; .endif\n\t"*/

extern int tee_config_device_secure(int dev_id, int secure);

bool vdec_tee_enabled(void);

int vdec_tee_load_video_fw_swap(u32 index, u32 vdec, bool is_swap);

int vdec_tee_load_video_fw(u32 index, u32 vdec);

int vdec_tee_vp9_prob_process(u32 cur_frame_type, u32 prev_frame_type,
		u32 prob_status, u32 prob_addr);

int vdec_tee_vp9_prob_malloc(u32 *prob_addr);

int vdec_tee_vp9_prob_free(u32 prob_addr);

#endif /* __SECPROT_H_ */

