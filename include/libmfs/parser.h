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

#ifndef __LIBMFS_PARSER_H__
#define __LIBMFS_PARSER_H__

#include "stream.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	/**
	 * The default state of parser
	 */
	MFSPARSER_STATE_NONE,

	/**
	 * This state indicated that the parser is parsing the Control Information Table.
	 */
	MFSPARSER_STATE_CIT,

	/**
	 * This state indicated that the parser is parsing the Multiplex Sub Frame.
	 */
	MFSPARSER_STATE_MSF,
} mfsparser_state_t;

struct mfsparser_visitor
{
	// TODO
};

typedef struct mfsparser* mfsparser_t;
struct mfsparser
{
	void* (*getheader)(mfsparser_t *self);

	mfsparser_state_t (*getstate)(mfsparser_t *self);

	void (*parse)(mfsparser_t *self, mfstream_t *stream, struct mfsparser_visitor *visitor);

	void (*free)(mfsparser_t *self);
};

extern mfsparser_t mfsparser_new(void);

#ifdef __cplusplus
}
#endif

#endif /* __LIBMFS_PARSER_H__ */

