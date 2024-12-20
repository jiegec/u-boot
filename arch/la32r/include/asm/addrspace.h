/* SPDX-License-Identifier: GPL-2.0+ */

/*
 * Copyright (C) 2023 by loongson.
 */
#ifndef _ASM_ADDRSPACE_H
#define _ASM_ADDRSPACE_H

#include <asm/mach-generic/spaces.h>

#define DIRECT_MAPPED_MEMORY_ADDR 0x0
#define CACHED_MEMORY_ADDR		  0xa0000000
#define UNCACHED_MEMORY_ADDR      0x80000000

#define CACHED_TO_PHYS(x)		VA_TO_PHYS(x)
#define UNCACHED_TO_PHYS(x)		VA_TO_PHYS(x)
#define PHYSADDR(x)				VA_TO_PHYS(x)
#define PHYS_TO_CACHED(x)		((x) | CACHED_MEMORY_ADDR)
#define PHYS_TO_UNCACHED(x)     ((x) | UNCACHED_MEMORY_ADDR)
#define CACHED_TO_UNCACHED(x)   (PHYS_TO_UNCACHED(VA_TO_PHYS(x)))
#define UNCACHED_TO_CACHED(x)   (PHYS_TO_CACHED(VA_TO_PHYS(x)))
#define VA_TO_PHYS(x)			((x) & 0x1fffffff)

#endif /* _ASM_ADDRSPACE_H */
