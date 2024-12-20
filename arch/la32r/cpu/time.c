// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2023
 */
#include <common.h>
#include <timer.h>
#include <asm/io.h>
#include <configs/la32rsoc_demo.h>

typedef struct 
{
    uint32_t low;
    uint32_t high;
} count;


ulong notrace get_tbclk(void)
{
    return CONFIG_SYS_LOONGARCH_TIMER_FREQ;
}

count timer_read_count(void)
{
    count ret;
    asm volatile("rdcntvl.w %0":"=r" (ret.low));
    asm volatile("rdcntvh.w %0":"=r" (ret.high));
    return ret;
}


bool timer_compare(count a, count b)
{
    if (a.high > b.high)
        return true;
    else if ((a.high == b.high) && (a.low >= b.low))
        return true;
    else
        return false;
}

count timer_add_ops(count a, count b)
{
    count ret;

	ret.low = a.low + b.low;
	ret.high = a.high + b.high + ((ret.low < a.low) ? 1 : 0);

    return ret;
}

static uint32_t timer_get_ticks(uint32_t usec)
{
    if (usec >  (0xffffffff / get_tbclk())) {
        printf("numerical overflow!!!\n");
        return 0xffffffff;
    }
    return usec * get_tbclk();
}

void __udelay(unsigned long usec)
{
    count tmp = {0,0};
    count end = {0,0};
    tmp.low = timer_get_ticks(usec);
    
    end = timer_add_ops(timer_read_count(),tmp);

    while (!(timer_compare(timer_read_count(), end)));
}

unsigned long get_timer(unsigned long base)
{

    unsigned long now;
	uint32_t high, low;
    uint32_t clk = get_tbclk() * 1000;/*ms*/
    
    count ret = timer_read_count();
    
    high = ret.high;
    low = ret.low;
    ret.high = high / clk;
    high = ((high % clk) << 16) | (low >> 16);
    ret.low = (high / clk) << 16;
    high = ((high % clk) << 16) | (low & 0xffff);
    ret.low |= (high / clk);
    
    now = ret.low;

    return now - base;
}

