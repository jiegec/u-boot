#include <common.h>

int board_init(void)
{
	return 0;
}

int board_late_init(void)
{
	return 0;
}

// code is taken from https://blog.csdn.net/a_weiming/article/details/116090948
#define STR1(x) #x
#ifndef STR
#define STR(x) STR1(x)
#endif

#define CFLUSH_D_L1_REG(rs1) \
	0xFC000073 |         \
	    (rs1 << (7 + 5 + 3)) |

#define CFLUSH_D_L1_ALL() \
	0xFC000073 |

#define FLUSH_D_ALL()                                                  \
	{                                                              \
		asm volatile(".word " STR(CFLUSH_D_L1_ALL()) "\n\t" :: \
				 : "memory");                          \
	}

//Stanard macro that passes rs1 via registers
#define FLUSH_D_REG(rs1) CFLUSH_D_L1_INST(rs1, 13)

//rs1 is data
//rs_1 si the register number to use
#define CFLUSH_D_L1_INST(rs1, rs1_n)                                                        \
	{                                                                                   \
		register uint32_t rs1_ asm("x" #rs1_n) = (uint32_t)rs1;                     \
		asm volatile(".word " STR(CFLUSH_D_L1_REG(rs1_n)) "\n\t" ::[_rs1] "r"(rs1_) \
			     : "memory");                                                   \
	}

// override weak functions in arch/riscv/lib/cache.c
void flush_dcache_all(void)
{
	FLUSH_D_ALL();
}

void flush_dcache_range(unsigned long start, unsigned long end)
{
	//printf("Flush DCache From: %lx\n", start);
	//printf("Flush DCache To: %lx\n", end);
	start = (start >> 6) * 64;
	end = (end >> 6) * 64;
	for (unsigned long addr = start; addr <= end; addr = addr + 64)
	{
		//printf("Flush DCache: %lx\n", addr);
		FLUSH_D_REG(addr);
	}
}