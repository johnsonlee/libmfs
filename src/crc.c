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

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "libmfs/crc.h"

typedef struct
{
	struct crc_context super;
	uint64_t crc_table[256];
} crc_context_impl_t;

const static uint64_t polynomial = 0x04C11DB7;

static inline uint64_t libmfs_crc_context_check8(crc_context_t *self, uint8_t *data, uint64_t length)
{
	assert(self && *self);

	uint64_t i;
	uint8_t crc = 0;

	while (length--) {
		crc ^= *data++;

		for (i = 0; i < 8; i++) {
			if (crc & 0x80) {
				crc = (crc << 1) ^ 0x31;
			} else {
				crc <<= 1;
			}
		}
	}

	return crc;
}

static inline uint64_t libmfs_crc_context_check32(crc_context_t *self, uint8_t *data, uint64_t length)
{
	assert(self && *self);

	uint64_t i, accum;
	crc_context_impl_t *impl = (crc_context_impl_t*) *self;

	for (i = 0, accum = -1; i < length; i++) {
		accum = (accum << 8) ^ impl->crc_table[(accum >> 24) ^ *data++];
	}

	return accum;
}

static inline void libmfs_crc_context_free(crc_context_t *self)
{
	assert(self && *self);

	free(*self);
	*self = NULL;
}

static inline void libmfs_crc_context_init(crc_context_impl_t *impl)
{
	uint64_t i, j, data, accum;

	for (i = 0; i < 256; i++) {
		data = i << 24;

		for (j = accum = 0; j < 8; j++) {
			if ((data ^ accum) & 0x80000000) {
				accum = (accum << 1) ^ polynomial;
			} else {
				accum <<= 1;
			}

			data <<= 1;
		}

		impl->crc_table[i] = accum;
	}
}

crc_context_t crc_context_new(void)
{
	const static struct crc_context ks_crc_context = {
		check8  : libmfs_crc_context_check8,
		check32 : libmfs_crc_context_check32,
		free    : libmfs_crc_context_free,
	};

	crc_context_impl_t *impl = calloc(1, sizeof(crc_context_impl_t));

	if (!impl) {
		// TODO 
		return NULL;
	}

	memcpy(&impl->super, &ks_crc_context, sizeof(struct crc_context));
	libmfs_crc_context_init(impl);

	return &impl->super;
}

