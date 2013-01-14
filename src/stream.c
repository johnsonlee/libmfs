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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libmfs/stream.h>

struct mfsblock
{
	uint8_t *data;
	size_t size;
	size_t offset;
	struct mfsblock *prev;
	struct mfsblock *next;
};

typedef struct
{
	struct mfstream super;
	struct mfsblock head;
} mfstream_impl_t;

#define libmfs_mfstream_readn(T, n)                         \
	int libmfs_mfstream_read##n(mfstream_t *self, T *value) \
	{                                                       \
		assert(self && *self);                              \
		assert(value);                                      \
                                                            \
		int i, c;                                           \
		mfstream_impl_t *impl = (mfstream_impl_t*) *self;   \
		struct mfsblock *block = impl->head.next;           \
                                                            \
		memset(value, 0, sizeof(*value));                   \
                                                            \
		for (i = (n - 1); i >= 0; i--) {                    \
			if (EOF == (c = libmfs_mfstream_read1(impl)))   \
				return EOF;                                 \
                                                            \
			*value |= (c & 0xff) << (8 * i);                \
		}                                                   \
                                                            \
		return n;                                           \
	}

static inline size_t libmfs_mfstream_available(mfstream_t *self)
{
	assert(self && *self);

	return ((mfstream_impl_t*) *self)->head.size;
}

static inline void libmfs_mfstream_clean(mfstream_impl_t *impl)
{
	struct mfsblock *head, *block;

	head = &impl->head;

	// remove all readed blockes
	for (block = head->next; block && block->size <= block->offset; block = head->next) {
		head->next = block->next;

		if (block->next) {
			block->next->prev = NULL;
		} else {
			head->prev = NULL;
		}

		if (block->data) {
			free(block->data);
		}

		free(block);
	}
}

static inline void libmfs_mfstream_free(mfstream_t *self)
{
	assert(self && *self);

	mfstream_impl_t *impl = (mfstream_impl_t*) *self;
	struct mfsblock *block, *head = &impl->head;

	// remove all blockes from head
	for (block = head->next; block; block = head->next) {
		head->next = block->next;

		if (block->next) {
			block->next->prev = NULL;
		} else {
			head->prev = NULL;
		}

		if (block->data) {
			free(block->data);
		}

		free(block);
	}

	free(*self);
	*self = NULL;
}

static inline int libmfs_mfstream_read1(mfstream_impl_t *impl)
{
	struct mfsblock *block = impl->head.next;

	libmfs_mfstream_clean(impl);

	if (block && block->data && block->size > block->offset)
		return block->data[block->offset++];

	return EOF;
}

static inline int libmfs_mfstream_read(mfstream_t *self)
{
	assert(self && *self);

	return libmfs_mfstream_read1((mfstream_impl_t*) *self);
}

static inline libmfs_mfstream_readn(uint16_t, 2)
static inline libmfs_mfstream_readn(uint32_t, 3)
static inline libmfs_mfstream_readn(uint32_t, 4)
static inline libmfs_mfstream_readn(uint64_t, 5)
static inline libmfs_mfstream_readn(uint64_t, 6)
static inline libmfs_mfstream_readn(uint64_t, 7)
static inline libmfs_mfstream_readn(uint64_t, 8)

static inline size_t libmfs_mfstream_reads(mfstream_t *self, void *buf, size_t n)
{
	assert(self && *self);
	assert(buf);

	size_t total = 0, bytes = 0;
	mfstream_impl_t *impl = (mfstream_impl_t*) *self;
	struct mfsblock *block, *head = &impl->head;

	libmfs_mfstream_clean(impl);

	for (block = head->next; block && total < n; block = block->next) {
		if (block->data && block->size > block->offset) {
			bytes = MIN(n - total, block->size - block->offset);
			memcpy(buf + total, block->data + block->offset, bytes);
			block->offset += bytes;
			total += bytes;
		}
	}

	return n;
}

static inline int libmfs_mfstream_unread(mfstream_t *self)
{
	assert(self && *self);

	mfstream_impl_t *impl = (mfstream_impl_t*) *self;
	struct mfsblock *block = impl->head.next;

	if (block && block->data && block->offset > 0) {
		block->offset--;
		return 0;
	}

	return EOF;
}

static inline size_t libmfs_mfstream_unreads(mfstream_t *self, size_t n)
{
	assert(self && *self);

	mfstream_impl_t *impl = (mfstream_impl_t*) *self;
	struct mfsblock *block = impl->head.next;

	if (block && block->data && block->offset > 0) {
		n = MIN(block->offset, n);
		block->offset -= n;
		return n;
	}

	return 0;
}

static inline size_t libmfs_mfstream_write(mfstream_t *self, const void *data, size_t n)
{
	assert(self && *self);

	struct mfsblock *head = &((mfstream_impl_t*) *self)->head;
	struct mfsblock *block = calloc(1, sizeof(struct mfsblock));

	if (!block) {
		// TODO
		return 0;
	}

	block->data = calloc(n, 1);

	if (!(block->data)) {
		// TODO
		free(block);
		return 0;
	}

	block->offset = 0;
	block->size = n;
	block->next = NULL;
	memcpy(block->data, data, n);

	if (NULL == head->prev && NULL == head->next) {
		head->next = head->prev = block;
		block->prev = NULL;
	} else {
		head->prev->next = block;
		block->prev = head->prev;
	}

	head->prev = block;

	return n;
}

mfstream_t mfstream_new(void)
{
	const static struct mfstream ks_mfstream = {
		available : libmfs_mfstream_available,
		free      : libmfs_mfstream_free,
		read      : libmfs_mfstream_read,
		read2     : libmfs_mfstream_read2,
		read3     : libmfs_mfstream_read3,
		read4     : libmfs_mfstream_read4,
		read5     : libmfs_mfstream_read5,
		read6     : libmfs_mfstream_read6,
		read7     : libmfs_mfstream_read7,
		read8     : libmfs_mfstream_read8,
		reads     : libmfs_mfstream_reads,
		unread    : libmfs_mfstream_unread,
		unreads   : libmfs_mfstream_unreads,
		write     : libmfs_mfstream_write,
	};

	mfstream_impl_t *impl = calloc(1, sizeof(mfstream_impl_t));

	if (!impl) {
		// TODO
		return NULL;
	}

	memcpy(&impl->super, &ks_mfstream, sizeof(struct mfstream));

	return &impl->super;
}

