/*
 * Copyright (c) 2019-2020, ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FCONF_H
#define FCONF_H

#include <stdint.h>

/* Public API */
#define FCONF_GET_PROPERTY(a, b, c)	a##__##b##_getter(c)

#define FCONF_REGISTER_POPULATOR(name, callback)				\
	__attribute__((used, section(".fconf_populator")))			\
	const struct fconf_populator name##__populator = {			\
		.info = #name,							\
		.populate = callback						\
	};

/*
 * Populator callback
 *
 * This structure are used by the fconf_populate function and should only be
 * defined by the FCONF_REGISTER_POPULATOR macro.
 */
struct fconf_populator {
	/* Description of the data loaded by the callback */
	const char *info;

	/* Callback used by fconf_populate function with a provided config dtb.
	 * Return 0 on success, err_code < 0 otherwise.
	 */
	int (*populate)(uintptr_t config);
};

/* Top level populate function
 *
 * This function takes a configuration dtb and calls all the registered
 * populator callback with it.
 *
 *  Panic on error.
 */
void fconf_populate(uintptr_t config);

#endif /* FCONF_H */
