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

#include <libmfs/parser.h>

typedef struct
{
	struct mfsparser super;
	mfsparser_state_t state;
	uint32_t msf_index;
	struct multiplx_frame_header *mf_header;
	struct network_information_table *nit;
	struct continual_service_multiplex_configuration_table *cmct;
	struct short_time_service_multiplex_configuration_table *smct;
	struct continual_service_configuration_table *csct;
	struct short_time_service_configuration_table *ssct;
} mfsparser_impl_t;

static inline int libmfs_mfsparser_locate_header(mfstream_t *stream)
{
	// TODO
	return -1;
}

static inline void libmfs_mfsparser_skip_current_sub_frame(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO
}

static inline void* libmfs_mfsparser_parse_network_information_table(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO

	return NULL;
}

static inline void* libmfs_mfsparser_parse_multiplex_configuration_table(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO

	return NULL;
}

static inline void* libmfs_mfsparser_parse_service_configuration_table(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO

	return NULL;
}

static inline void* libmfs_mfsparser_parse_esg_basic_description_table(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO

	return NULL;
}

static inline void* libmfs_mfsparser_parse_emergency_broadcasting(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO

	return NULL;
}

static inline void* libmfs_mfsparser_parse_encryption_and_authorization_description_table(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO

	return NULL;
}

static inline void* libmfs_mfsparser_parse_common_information_description_table(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO

	return NULL;
}

static inline void* libmfs_mfsparser_parse_multiplex_frame_header(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO
	return NULL;
}

static inline void* libmfs_mfsparser_parse_multiplex_sub_frame(mfsparser_impl_t *impl, mfstream_t *stream)
{
	// TODO

	return NULL;
}

static inline void libmfs_mfsparser_free(mfsparser_t *self)
{
	assert(self && *self);

	free(*self);
	*self = NULL;
}

static inline void* libmfs_mfsparser_get_multiplex_frame_header(mfsparser_t *self)
{
	assert(self && *self);

	return ((mfsparser_impl_t*) *self)->mf_header;
}

static inline mfsparser_state_t libmfs_mfsparser_get_state(mfsparser_t *self)
{
	assert(self && *self);

	return ((mfsparser_impl_t*) *self)->state;
}

static inline void libmfs_mfsparser_parse(mfsparser_t *self, mfstream_t *stream, struct mfsparser_visitor *visitor)
{
	assert(self && *self);
	assert(stream && *stream);

	// TODO
}

mfsparser_t mfsparser_new(void)
{
	const static struct mfsparser ks_mfsparser = {
		free        : libmfs_mfsparser_free,
		getheader   : libmfs_mfsparser_get_multiplex_frame_header,
		getstate    : libmfs_mfsparser_get_state,
		parse       : libmfs_mfsparser_parse,
	};

	mfsparser_impl_t *impl = calloc(1, sizeof(mfsparser_impl_t));

	if (!impl) {
		// TODO
		return NULL;
	}

	memcpy(&impl->super, &ks_mfsparser, sizeof(struct mfsparser));

	return &impl->super;
}

int main(int argc, char *argv[])
{
	return 0;
}

