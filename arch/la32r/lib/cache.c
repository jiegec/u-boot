// SPDX-License-Identifier: GPL-2.0+

#include <common.h>
#include <asm/cacheops.h>
#include <asm/io.h>
#include <asm/la32rregs.h>

DECLARE_GLOBAL_DATA_PTR;

static inline unsigned long icache_line_size(void)
{
	return CONFIG_SYS_ICACHE_LINE_SIZE;
}

static inline unsigned long dcache_line_size(void)
{
	return CONFIG_SYS_DCACHE_LINE_SIZE;
}

#define cache_loop(start, size, lsize, ops)                          \
	do                                                               \
	{                                                                \
		const void *addr = (const void *)(start & ~(lsize - 1));     \
		unsigned int count;                                          \
		unsigned new_size;                                           \
        new_size = (start & (lsize - 1)) ? size + (lsize - (start & (lsize - 1))) : size;       \
                                                                     \
		for (count = 0; lsize * count < new_size; count++) {         \
				la32r_cache(ops, addr + lsize * count);     \
		}                                                            \
	} while (0)

void flush_cache(ulong start_addr, ulong size)
{

	/* flush D-cache */
	cache_loop(start_addr, size, dcache_line_size(), HIT_WRITEBACK_INV_D);
    
	sync();

}

void flush_dcache_range(ulong start_addr, ulong stop)
{
    flush_cache(start_addr, (stop - start_addr));
}

void invalidate_dcache_range(ulong start_addr, ulong stop)
{
    flush_cache(start_addr, (stop - start_addr));
}

void dcache_enable(void)
{
}

void dcache_disable(void)
{
}

int dcache_status(void)
{
	return 1;
}
