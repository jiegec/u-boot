/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Cache operations for the cache instruction.
 *
 * (C) Copyright 1996, 97, 99, 2002, 03 Ralf Baechle
 * (C) Copyright 1999 Silicon Graphics, Inc.
 */
#ifndef	__ASM_CACHEOPS_H
#define	__ASM_CACHEOPS_H

#ifndef __ASSEMBLY__

static inline void la32r_cache(int op, const volatile void *addr)
{
	__asm__ __volatile__("cacop	%0, %1" : : "i"(op), "R" (*(unsigned char *)(addr)));
}

#define LA32R_WHICH_ICACHE                    0x0
#define LA32R_FETCH_AND_LOCK                  0x7

#define ICACHE_LOAD_LOCK (LA32R_WHICH_ICACHE | (LA32R_FETCH_AND_LOCK << 2))

/* Prefetch and lock instructions into cache */
static inline void icache_lock(void *func, size_t len)
{
}
#endif /* !__ASSEMBLY__ */

#define Cache_I				0x00
#define Cache_D				0x01
#define Cache_V				0x02
#define Cache_S				0x03

#define INDEX_INVALIDATE		0x08
#define INDEX_WRITEBACK_INV		0x08
#define HIT_INVALIDATE			0x10
#define HIT_WRITEBACK_INV		0x10

#define INDEX_INVALIDATE_I		(Cache_I | INDEX_INVALIDATE)
#define INDEX_WRITEBACK_INV_D	(Cache_D | INDEX_WRITEBACK_INV)
#define HIT_INVALIDATE_I		(Cache_I | HIT_INVALIDATE)
#define HIT_INVALIDATE_D		(Cache_D | HIT_INVALIDATE)
#define HIT_WRITEBACK_INV_D		(Cache_D | HIT_WRITEBACK_INV)

#endif	/* __ASM_CACHEOPS_H */
