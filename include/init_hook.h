/* Copyright (c) 2013 The F9 Microkernel Project. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef INIT_HOOK_H_
#define INIT_HOOK_H_

enum init_levels {
	INIT_LEVEL_EARLIEST	= 1,
	INIT_LEVEL_PLATFORM	= 0x1000,
	INIT_LEVEL_KERNEL	= 0x2000,
	INIT_LEVEL_LAST		= 0xFFFFFFFF,
};

typedef void (*init_hook_t)(unsigned int level);

typedef struct {
	unsigned int level;
	init_hook_t hook;
	const char *hook_name;
} init_struct;

#define INIT_HOOK(_name,_hook,_level) \
	const init_struct _init_struct_##_name \
			__attribute__((section(".init_hook"))) = { \
		.level = _level, \
		.hook = _hook, \
		.hook_name = #_name, \
	};

int init_hook(unsigned int level);

#endif /* INIT_HOOK_H_ */
