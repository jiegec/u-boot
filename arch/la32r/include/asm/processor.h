/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 1999, 2000 Silicon Graphics, Inc.
 */
#ifndef _ASM_PROCESSOR_H
#define _ASM_PROCESSOR_H


#include <asm/cachectl.h>
#include <asm/la32rregs.h>
#include <asm/reg.h>

/*
 * Return current * instruction pointer ("program counter").
 */
#define current_text_addr() ({ __label__ _l; _l: &&_l;})

/*
 * System setup and hardware flags..
 */
extern void (*cpu_wait)(void);

extern unsigned int vced_count, vcei_count;

#define NUM_FPU_REGS	32

typedef __u64 fpureg_t;



#endif /* _ASM_PROCESSOR_H */
