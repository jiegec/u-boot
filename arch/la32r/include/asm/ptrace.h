/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 1994, 95, 96, 97, 98, 99, 2000 by Ralf Baechle
 * Copyright (C) 1999, 2000 Silicon Graphics, Inc.
 */
#ifndef _ASM_PTRACE_H
#define _ASM_PTRACE_H

#include <linux/compiler.h>
#include <linux/types.h>

/*
 * This struct defines the way the registers are stored on the stack during a
 * system call/exception. As usual the registers k0/k1 aren't being saved.
 *
 * If you add a register here, also add it to regoffset_table[] in
 * arch/la32r/kernel/ptrace.c.
 */
struct pt_regs {
#ifdef CONFIG_32BIT
	/* Pad bytes for argument save space on the stack. */
	unsigned long pad0[8];
#endif

	/* Saved main processor registers. */
	unsigned long regs[32];

#ifdef CONFIG_CPU_CAVIUM_OCTEON
	unsigned long long mpl[6];        /* MTM{0-5} */
	unsigned long long mtp[6];        /* MTP{0-5} */
#endif
	unsigned long __last[0];
} __aligned(8);

#endif /* _ASM_PTRACE_H */
