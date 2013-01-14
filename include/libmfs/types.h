/* 
 * Copyright (c) 2012 by Johnson Lee <g.johnsonlee@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef __LIBMFS_TYPES_H__
#define __LIBMFS_TYPES_H__

#include <stdint.h>
#include <stdlib.h>

#ifndef __GNUC__
#define __attribute__(x)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Byte Inter Leaved Mode
 * 
 * @size 2-bits
 * 
 * @description the valid range is [1, 3]
 */
typedef enum
{
	/**
	 * mode 1
	 */
	BYTE_INTER_LEAVED_MODE_1 = 0x01,

	/**
	 * mode 2
	 */
	BYTE_INTER_LEAVED_MODE_2 = 0x02,

	/**
	 * mode 3
	 */
	BYTE_INTER_LEAVED_MODE_3 = 0x03,

} byte_inter_leaved_mode_t;

/**
 * Control Information Type Id
 * 
 * @size 8-bits
 * 
 * @description the valid range is [0x01, 0xFF], [0x08, 0x0F] and [0x11, 0xFF] are reserved.
 */
typedef enum
{
	/**
	 * ID of Network Information Table
	 */
	CTRL_INFO_TABLE_NIT    = 0x01,

	/**
	 * ID of Continual service Multiplex Configuration Table
	 */
	CTRL_INFO_TABLE_CMCT   = 0x02,

	/**
	 * ID of Continual Service Configuration Table
	 */
	CTRL_INFO_TABLE_CSCT   = 0x03,

	/**
	 * ID of Short time service Multiplex Configuration Table
	 */
	CTRL_INFO_TABLE_SMCT   = 0x04,

	/**
	 * ID of Short time Service Configuration Table
	 */
	CTRL_INFO_TABLE_SSCT   = 0x05,

	/**
	 * ID of ESG Basic Description Table
	 */
	CTRL_INFO_TABLE_ESGBDT = 0x06,

	/**
	 * ID of Encryption and Authorization Description Table
	 */
	CTRL_INFO_TABLE_EADT   = 0x07,

	/**
	 * ID of Emergency Broadcasting
	 */
	CTRL_INFO_TABLE_EB     = 0x10,

	/**
	 * ID of Common Information Description Table
	 */
	CTRL_INFO_TABLE_CIDT   = 0x11,

} ctrl_info_table_id_t;

/**
 * Data unit type
 */
typedef enum
{
	/**
	 * ESG data
	 */
	DATA_UNIT_TYPE_ESG     = 0x00,

	/**
	 * Program information
	 */
	DATA_UNIT_TYPE_PROGRAM = 0x01,

	/**
	 * ECM(128)
	 */
	DATA_UNIT_TYPE_ECM_128 = 0x80,

	/**
	 * ECM(128)
	 */
	DATA_UNIT_TYPE_ECM_129 = 0x81,

	/**
	 * ECM(128)
	 */
	DATA_UNIT_TYPE_ECM_130 = 0x82,

	/**
	 * ECM(128)
	 */
	DATA_UNIT_TYPE_ECM_131 = 0x83,

	/**
	 * ECM(128)
	 */
	DATA_UNIT_TYPE_ECM_132 = 0x84,

	/**
	 * ECM(128)
	 */
	DATA_UNIT_TYPE_ECM_133 = 0x85,

	/**
	 * XPE data
	 */
	DATA_UNIT_TYPE_XPE     = 0xA0,

	/**
	 * XPE-FEC data
	 */
	DATA_UNIT_TYPE_XPE_FEC = 0xA1,

} data_unit_type_t;

/**
 * Encapsulation mode
 */
typedef enum
{
	/**
	 * Encapsulation mode 2
	 */
	ENCAPSULATION_MODE_2 = 0x00,

	/**
	 * Encapsulation mode 1
	 */
	ENCAPSULATION_MODE_1 = 0x01,

} encapsulation_mode_t;

/**
 * Frame Frequency
 * 
 * @size
 */
typedef enum
{
	/**
	 * 25 Hz
	 */
	FRAME_FREQUENCY_25HZ   = 0x00,

	/**
	 * 30 Hz
	 */
	FRAME_FREQUENCY_30HZ   = 0x01,

	/**
	 * 12.5 Hz
	 */
	FRAME_FREQUENCY_12_5HZ = 0x02,

	/**
	 * 15 Hz
	 */
	FRAME_FREQUENCY_15HZ   = 0x03,

} frame_frequency_t;

/**
 * Image frame type
 *
 * 3-bits
 *
 * the invalid range is [0, 7], and range [3, 7] are reserved.
 */
typedef enum
{
	/**
	 * I frame
	 */
	IMAGE_FRAME_TYPE_I = 0x00,

	/**
	 * P frame
	 */
	IMAGE_FRAME_TYPE_P = 0x01,

	/**
	 * B frame
	 */
	IMAGE_FRAME_TYPE_B = 0x02,

} image_frame_type_t;

/**
 * Low Density Parity Check code rate
 * 
 * 2-bits 
 */
typedef enum
{
	/**
	 * 1/2
	 */
	LDPC_CODE_RATE_1_2 = 0x00,

	/**
	 * 3/4
	 */
	LDPC_CODE_RATE_3_4 = 0x01,

} ldpc_code_rate_t;

/**
 * Modulation method
 *
 * 2-bits
 * 
 * the valid range is [0, 3], and range [3] is reserved.
 */
typedef enum
{
	/**
	 * Binary Phase Shift Keying
	 */
	MODULATION_METHOD_BPSK  = 0x00,

	/**
	 * Quadrature Phase Shift Keying
	 */
	MODULATION_METHOD_QPSK  = 0x01,

	/**
	 * Quadrature Amplitude Modulation
	 */
	MODULATION_METHOD_16QAM = 0x02,

} modulation_mothod_t;

typedef enum
{
	/**
	 * (240, 240)
	 */
	RS_CODE_RATE_240_240 = 0x00,

	/**
	 * (240, 224)
	 */
	RS_CODE_RATE_240_224 = 0x01,

	/**
	 * (240, 192)
	 */
	RS_CODE_RATE_240_192 = 0x02,

	/**
	 * (240, 176)
	 */
	RS_CODE_RATE_240_176 = 0x03,

} rs_code_rate_t;

typedef enum
{
	/**
	 * 8 kHz
	 */
	SAMPLE_RATE_8KHZ     = 0x00,

	/**
	 * 12 kHz
	 */
	SAMPLE_RATE_12KHZ    = 0x01,

	/**
	 * 16 kHz
	 */
	SAMPLE_RATE_16KHZ    = 0x02,

	/**
	 * 20.05 kHz
	 */
	SAMPLE_RATE_20_05KHZ = 0x03,

	/**
	 * 24 kHz
	 */
	SAMPLE_RATE_24KHZ    = 0x04,

	/**
	 * 32 kHz
	 */
	SAMPLE_RATE_32KHZ    = 0x05,

	/**
	 * 44.1 kHz
	 */
	SAMPLE_RATE_44_1KHZ  = 0x06,

	/**
	 * 48 kHz
	 */
	SAMPLE_RATE_48KHZ    = 0x07,

	/**
	 * 96 kHz
	 */
	SAMPLE_RATE_96KHZ    = 0x08,

} sample_rate_t;

typedef enum
{
	/**
	 * method 0
	 */
	SCRAMBLE_METHOD_0 = 0x00,

	/**
	 * method 1
	 */
	SCRAMBLE_METHOD_1 = 0x01,

	/**
	 * method 2
	 */
	SCRAMBLE_METHOD_2 = 0x02,

	/**
	 * method 3
	 */
	SCRAMBLE_METHOD_3 = 0x03,

	/**
	 * method 4
	 */
	SCRAMBLE_METHOD_4 = 0x04,

	/**
	 * method 5
	 */
	SCRAMBLE_METHOD_5 = 0x05,

	/**
	 * method 6
	 */
	SCRAMBLE_METHOD_6 = 0x06,

	/**
	 * method 7
	 */
	SCRAMBLE_METHOD_7 = 0x07,

} scramble_method_t;

/**
 * Service mode
 */
typedef enum
{
	/**
	 * Stream mode
	 */
	SERVICE_MODE_STREAM = 0x00,

	/**
	 * File mode
	 */
	SERVICE_MODE_FILE   = 0x01,

} service_mode_t;

struct next_frame_param
{
	/**
	 * the header length of next frame
	 */
	uint32_t header_length               : 8;

	/**
	 * the length of the first multiplex sub frame
	 */
	uint32_t frame1_length               : 24;

	/**
	 * the length of the first multiplex sub frame header
	 */
	uint8_t  frame1_header_length        : 8;

} __attribute__((packed));

struct multiplex_frame_header
{
	/**
	 * the start code indicate the beginning of a multiplex frame, it's always 0x00000001.
	 */
	uint32_t start_code                  : 32;

	/**
	 * the length of the multiplex frame header, excluding CRC_32.
	 */
	uint32_t length                      : 8;

	/**
	 * the id of the multiplex frame, if the id equals 0,
	 * the multiplex frame is used to carry control information,
	 * and each multiplex sub frame corresponding to a control information table;
	 * if the id not equals 0, the multiplex frame is used to carry services,
	 * and each multiplex sub frame corresponding to a service.
	 */
	uint32_t id                          : 6;
	uint32_t protocol_min_version        : 5;
	uint32_t protocol_version            : 5;

	/**
	 * control table update index ahead flag
	 */
	uint32_t ctuia_flag                  : 2;
	uint32_t                             : 3;

	/**
	 * next frame params flag
	 */
	uint32_t nfp_flag                    : 1;

	/**
	 * emergency broadcast flag
	 */
	uint32_t eb_flag                     : 2;

	/**
	 * continual service multiplex configuration table update index
	 */
	uint32_t cmct_update_index           : 4;

	/**
	 * network information table update index
	 */
	uint32_t nit_update_index            : 4;

	/**
	 * short time service multiplex configuration table update index
	 */
	uint32_t smct_update_index           : 4;

	/**
	 * continual service configuration table update index
	 */
	uint32_t csct_update_index           : 4;

	/**
	 * eletronic servuce guide update index
	 */
	uint32_t esg_update_index            : 4;

	/**
	 * short time service configuration table update index
	 */
	uint32_t ssct_update_index           : 4;

	/**
	 * the number of multiplex sub frame
	 */
	uint32_t sub_frame_count             : 4;

	/**
	 * extended area update index
	 */
	uint32_t ext_update_index            : 4;

	/**
	 * the lengths of each multiplex sub frame
	 */
	uint32_t *sub_frame_lengths;

	/**
	 * the next frame params, it exists when the next frame params flag equals 1
	 */
	struct next_frame_param *next_frame_params;

} __attribute__((packed));

struct frequency_point
{
	uint64_t index                       : 8;

	uint64_t central_frequency           : 32;

	uint64_t band_width                  : 4;

	uint64_t                             : 4;

} __attribute__((packed));

struct adjacent_network
{
	uint64_t id                          : 12;

	uint64_t level                       : 4;

	uint64_t frequency_point_index       : 8;

	uint64_t central_frequency           : 32;

	uint64_t                             : 4;

	uint64_t band_width                  : 4;

} __attribute__((packed));

struct time_slot
{
	uint8_t                              : 2;

	uint8_t index                        : 6;

} __attribute__((packed));

struct multiplex_sub_frame_param
{
	uint32_t                             : 4;

	uint32_t index                       : 4;

	uint32_t service_id                  : 16;

} __attribute__((packed));

struct multiplex_frame_param
{
	uint32_t rs_rate                     : 2;

	uint32_t id                          : 6;

	uint32_t time_slot_count             : 6;

	uint32_t scramble_method             : 3;

	uint32_t                             : 1;

	uint32_t modulation_method           : 2;

	uint32_t ldpc_rate                   : 2;

	uint32_t byte_inter_leave_mode       : 2;

	uint32_t sub_frame_count             : 4;

	uint32_t                             : 4;

	struct time_slot *timeslots;

	struct multiplex_sub_frame_param *sub_frame_params;

} __attribute__((packed));

struct service
{
	uint32_t id                          : 16;

	uint32_t frequency_point_index       : 8;

} __attribute__((packed));

/**
 * Common information
 */
struct common_info
{
	uint32_t custom_id                   : 16;

	uint32_t ext_flag                    : 16;

	uint32_t                             : 4;

	uint32_t update_index                : 4;

	uint32_t service_id                  : 16;

	uint32_t custom_name_length          : 8;

	uint8_t *custom_name;

	uint8_t trigger_msg_length           : 8;

	uint8_t *trigger_msg;

} __attribute__((packed));

/**
 * NIT (Network Information Table) is a kind of the control information table
 */
struct network_info_table
{
	uint32_t id                          : 8;

	uint32_t                             : 4;

	uint32_t update_index                : 4;

	uint32_t systime_mjd                 : 16;
	uint32_t systime_bcd                 : 24;

	uint64_t country_code                : 24;

	uint64_t net_id                      : 12;

	uint64_t net_level                   : 4;

	uint8_t net_name_length              : 8;

	uint8_t *net_name;

	uint8_t frequency_point_index        : 8;

	uint32_t central_frequency           : 32;

	uint16_t other_frequency_point_count : 4;

	uint16_t band_width                  : 4;

	uint16_t                             : 4;

	uint16_t adjacent_network_count      : 4;

	struct frequency_point *other_frequency_points;

	struct adjacent_network *adjacent_networks;

} __attribute__((packed));

/**
 * Multiplex Configuration Table is a set of control information table, it includes: CMCT (Continual Multiplex Configuration Table) and SMCT (Short time Multiplex Configuration Table)
 */
struct multiplex_configuration_table
{
	uint32_t id                          : 8;

	uint32_t frequency_point_index       : 8;

	uint32_t multiplex_frame_count       : 6;

	uint32_t                             : 6;

	uint32_t update_index                : 4;

	struct multiplex_frame_param * multiplex_frame_params;

} __attribute__((packed));

/**
 * Service Configuration Table is a set of control information table, it includes: CSCT (Continual Service Configuration Table) and SSCT (Short time Service Configuration Table)
 */
struct service_configuration_table
{
	uint32_t id                          : 8;

	uint32_t section_length              : 16;

	uint32_t section_index               : 8;

	uint32_t section_count               : 8;

	uint32_t                             : 4;

	uint32_t update_index                : 4;

	uint32_t service_count               : 16;

	struct service *services;

} __attribute__((packed));

/**
 * EBDT (ESG Basic Description Table) is a kind of control information table.
 */
struct esg_basic_description_table
{
	uint8_t id                           : 8;

} __attribute__((packed));

/**
 * EADT (Encryption and Authorization Description Table) is a kind of control information table.
 */
struct encryption_and_authorization_description_table
{
	uint8_t id                           : 8;

} __attribute__((packed));

/**
 * CIDT (Common Information Description Table) is a kind of control information table.
 */
struct common_info_description_table
{
	uint8_t id                           : 8;

	uint32_t                             : 12;
	uint32_t update_index                : 4;

	union {
		uint32_t data_length             : 16;
		uint32_t common_info_count       : 16;
	};

	struct common_info *common_infos;

} __attribute__((packed));

/**
 * EB (Emergency Broadcasting) is a kind of control information table.
 */
struct emergency_broadcasting
{
	uint32_t id                          : 8;

	uint32_t msg_count                   : 4;

	uint32_t                             : 2;

	uint32_t index                       : 2;

	uint32_t data_length                 : 16;

	uint8_t *data;

} __attribute__((packed));

/**
 * Emergency Broadcasting Data Section
 */
struct emergency_broadcasting_data_section
{
	uint16_t protocol_version            : 4;

	uint16_t protocol_min_version        : 4;

	uint16_t network_level               : 4;

	uint16_t network_id                  : 12;

	uint16_t msg_id                      : 16;

	uint16_t current_section_index       : 8;

	uint16_t last_section_index          : 8;

	uint16_t                             : 3;

	uint16_t data_length                 : 13;

	uint8_t *data;

} __attribute__((packed));

/**
 * Emergency Broadcasting Trigger Param
 */
struct emergency_broadcasting_trigger_param
{
} __attribute__((packed));

/**
 * Emergency Broadcasting Message Param
 */
struct emergency_broadcasting_msg_param
{
} __attribute__((packed));

/**
 * Emergency Broadcasting Message
 */
struct emergency_broadcasting_msg
{
	uint32_t trigger_flag                : 1;

	union {
		struct emergency_broadcasting_trigger_param *trigger_param;
		struct emergency_broadcasting_msg_param *msg_param;
	};

} __attribute__((packed));

/**
 * Section Size
 */
struct section_size
{
	uint32_t stream_count                : 3;

	uint32_t length                      : 21;

} __attribute__((packed));

/**
 * Display Param
 */
struct display_param
{
	uint16_t x                           : 6;

	uint16_t y                           : 6;

	uint16_t priority                    : 3;

	uint16_t                             : 1;
	
} __attribute__((packed));

/**
 * Resolution Param
 */
struct resolution_param
{
	uint32_t                             : 4;

	uint32_t width                       : 10;

	uint32_t height                      : 10;

} __attribute__((packed));

/**
 * Video Stream Param
 */
struct video_stream_param
{
	uint32_t algorithm_type              : 3;

	uint32_t code_rate_flag              : 1;

	uint32_t display_flag                : 1;

	uint32_t resolution_flag             : 1;

	uint32_t frame_frequency_flag        : 1;

	uint32_t                             : 1;

	uint32_t code_rate                   : 16;

	uint32_t frame_frequency             : 4;

	uint32_t                             : 4;

	struct display_param *display_param;

	struct resolution_param *resolution_param;

} __attribute__((packed));

/**
 * Audio Stream Param
 */
struct audio_stream_param
{
	uint32_t                             : 1;

	/**
	 * description flag
	 */
	uint32_t desc_flag                   : 1;

	uint32_t sample_rate_flag            : 1;

	uint32_t code_rate_flag              : 1;

	uint32_t algorithm_type              : 4;

	uint32_t                             : 2;

	uint32_t code_rate                   : 14;

	uint32_t sample_reate                : 4;

	uint32_t                             : 4;

	/**
	 * the language of the audio stream
	 */
	uint32_t desc                        : 24;

} __attribute__((packed));

/**
 * Video Unit Param
 */
struct video_unit_param
{
	uint16_t length                      : 16;

	uint8_t play_time_flag               : 1;

	uint8_t frame_end_flag               : 1;

	uint8_t stream_index                 : 3;

	uint8_t frame_type                   : 3;

	uint16_t play_time                   : 16;

} __attribute__((packed));

/**
 * Audio Unit Param
 */
struct audio_unit_param
{
	uint16_t length                      : 16;

	uint16_t                             : 5;

	uint16_t stream_index                : 3;

	uint16_t play_time                   : 16;

} __attribute__((packed));

/**
 * Data Unit Param
 */
struct data_unit_param
{
	uint8_t type                         : 8;

	uint16_t length                      : 16;

} __attribute__((packed));

/**
 * Multiplex Sub Frame Header
 */
struct multiplex_sub_frame_header
{
	uint16_t length                      : 8;

	uint16_t pkg_mode_flag               : 1;

	uint16_t encryption_flag             : 2;

	uint16_t ext_flag                    : 1;

	uint16_t data_section_flag           : 1;

	uint16_t audio_section_flag          : 1;

	uint16_t video_section_flag          : 1;

	uint16_t start_play_time_flag        : 1;

	uint32_t start_play_time             : 32;

	struct section_size *video_section_size;

	struct section_size *audio_section_size;

	struct section_size *data_section_size;

	struct video_stream_param *video_stream_params;

	struct audio_stream_param *audio_stream_params;

} __attribute__((packed));

/**
 * Video Section
 */
struct video_section
{
	uint16_t                             : 4;
	uint16_t unit_count                  : 12;

	struct video_unit_param *unit_params;

	uint8_t *data;

} __attribute__((packed));

/**
 * Audio Section
 */
struct audio_section
{
	uint8_t unit_count                   : 8;

	struct audio_unit_param *unit_params;

	uint8_t *data;

} __attribute__((packed));

/**
 * Data Section
 */
struct data_section
{
	uint8_t unit_count                   : 8;

	struct data_unit_param *unit_params;

	uint8_t *data;

} __attribute__((packed));

/**
 * Multiplex Sub Frame
 */
struct multiplex_sub_frame
{
	struct multiplex_sub_frame_header *header;

	struct video_section *video_section;

	struct audio_section *audio_section;

	struct data_section *data_section;

} __attribute__((packed));

#ifdef __cplusplus
}
#endif

#endif /* __LIBMFS_TYPES_H__ */

