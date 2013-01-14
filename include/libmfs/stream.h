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

#ifndef __LIBMFS_STREAM_H__
#define __LIBMFS_STREAM_H__

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mfstream* mfstream_t;
struct mfstream {
	size_t (*available)(mfstream_t *self);

	void (*free)(mfstream_t *self);

	int (*read)(mfstream_t *self);

	int (*read2)(mfstream_t *self, uint16_t *value);

	int (*read3)(mfstream_t *self, uint32_t *value);

	int (*read4)(mfstream_t *self, uint32_t *value);

	int (*read5)(mfstream_t *self, uint64_t *value);

	int (*read6)(mfstream_t *self, uint64_t *value);

	int (*read7)(mfstream_t *self, uint64_t *value);

	int (*read8)(mfstream_t *self, uint64_t *value);

	size_t (*reads)(mfstream_t *self, void *buf, size_t n);

	int (*unread)(mfstream_t *self);

	size_t (*unreads)(mfstream_t *self, size_t n);

	size_t (*write)(mfstream_t *self, const void *data, size_t n);
};

extern mfstream_t mfstream_new(void);

#ifdef __cplusplus
}
#endif

#endif /* __LIBMFS_STREAM_H__ */

