// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, <wd@denx.de>
 */

#include <common.h>
#include <asm/types.h>
#include <asm/la32rregs.h>
#include <larchintrin.h>

void enable_interrupts(void)
{
}

int disable_interrupts(void)
{
    return 0;
}

int interrupt_init(void)
{
#if 0
    unsigned int val;

    val = __csrrd(csr_crmd);
    __csrwr(val | 0x4, csr_crmd);
#endif 
    return 0;
}
