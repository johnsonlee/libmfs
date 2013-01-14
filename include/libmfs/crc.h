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

#ifndef __LIBMFS_CRC_H__
#define __LIBMFS_CRC_H__

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct crc_context* crc_context_t;

struct crc_context
{
	uint64_t (*check8)(crc_context_t *self, uint8_t *data, uint64_t length);

	uint64_t (*check32)(crc_context_t *self, uint8_t *data, uint64_t length);

	void (*free)(crc_context_t *self);
};

extern crc_context_t crc_context_new(void);

#ifdef __cplusplus
}
#endif

#endif /* __LIBMFS_CRC_H__ */

