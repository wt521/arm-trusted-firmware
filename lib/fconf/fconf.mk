#
# Copyright (c) 2019-2020, ARM Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

# Add Firmware Configuration files
FCONF_SOURCES		:=	lib/fconf/fconf.c

BL1_SOURCES		+=	${FCONF_SOURCES}
BL2_SOURCES		+=	${FCONF_SOURCES}
