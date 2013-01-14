# 
# Copyright (c) 2012 by Johnson Lee <g.johnsonlee@gmail.com>
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#

AC_PREREQ([2.59])
AC_INIT([libmfs], [1.0], [g.johnsonlee@gmail.com], [libmfs], [https://github.com/johnsonlee/libmfs.git])
AC_CONFIG_AUX_DIR([aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE

AC_LANG_C
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
AM_PROG_CC_C_O

AC_ARG_ENABLE([debug],
  [  --enable-debug          Turn on debugging],
  [case "${enableval}" in
    yes) debug=true; CFLAGS="-O0 -g3 -ggdb"; CXXFLAGS="-O0 -g3 -ggdb";;
    no) debug=false;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-debug]);;
   esac],
  [debug=false])
AM_CONDITIONAL([DEBUG], [test "x$debug" = xtrue])

LT_INIT

AC_CONFIG_FILES([
    Makefile
    include/Makefile
    include/libmfs/Makefile
    src/Makefile
])

AC_OUTPUT

