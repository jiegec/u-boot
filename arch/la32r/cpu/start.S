/* SPDX-License-Identifier: GPL-2.0+ */
/*
 *  Startup Code for LA32R CPU-core
 *
 *  Copyright (c) 2023 
 */

#include <asm-offsets.h>
#include <config.h>
#include <asm/asm.h>
#include <asm/regdef.h>
#include <asm/la32rregs.h>
#include <asm/addrspace.h>

#ifndef CONFIG_SYS_INIT_SP_ADDR
#define CONFIG_SYS_INIT_SP_ADDR	(CONFIG_SYS_SDRAM_BASE + \
				CONFIG_SYS_INIT_SP_OFFSET)
#endif

.macro setup_stack_gd
	li.w	t0, -16
	li.w	t1, CONFIG_SYS_INIT_SP_ADDR
	and		sp, t1, t0		# force 16 byte alignment
	addi.w	sp, sp, -GD_SIZE		# reserve space for gd
	and		sp, sp, t0		# force 16 byte alignment
	add.w	x0, sp, zero			# save gd pointer
#if CONFIG_VAL(SYS_MALLOC_F_LEN)
	li.w	t2, CONFIG_VAL(SYS_MALLOC_F_LEN)
	sub.w	sp, sp, t2		# reserve space for early malloc
	and		sp, sp, t0		# force 16 byte alignment
#endif
	add.w	fp, sp, zero

	/* Clear gd */
	add.w	t0, x0, zero
1:
	st.w	zero, t0, 0
	addi.w	t0, t0, 4
	blt	t0, t1, 1b

#if CONFIG_VAL(SYS_MALLOC_F_LEN)
	st.w	sp, x0, GD_MALLOC_BASE
#endif
	.endm

ENTRY(_start)
	/* U-Boot entry point */
	bl	reset

uncached:
	nop 

reset:
	/* compute relocation offset */
	la      s0, uncached 
	sub.w   s0, ra, s0

	/* cached window, cache attribute is set after */
	li.w    t1, CACHED_MEMORY_ADDR | 0x9 
	csrwr   t1, csr_dmw0 

	/* uncached window, temporary */
	li.w    t1, DIRECT_MAPPED_MEMORY_ADDR | 0x9  
	csrwr   t1, csr_dmw1

	/* enable DATF */
	li.w    t1, 0x30 
	li.w    t2, 0x78 
	csrxchg t1, t2, csr_crmd 
	
	b relocate
relocate:
	la      t0, _start 
	la      t2, _end  
	
	add.w   t1, t0, s0 /* link addr to 0x1c000000 */

	/* relocate text section */ 
loop:
	ld.w    t3, t1, 0 
	st.w    t3, t0, 0 
	addi.w  t0, t0, 4 
	addi.w  t1, t1, 4 
	bne     t2, t0, loop

	li.w    t1, CACHED_MEMORY_ADDR | 0x19 //cache window 
	csrwr   t1, csr_dmw0 

	la      t0, c_main
	jirl    zero, t0, 0

c_main:
	li.w    t1, UNCACHED_MEMORY_ADDR | 0x9  
	csrwr   t1, csr_dmw1

 	/* Set up initial stack and global data */
	setup_stack_gd

	/* enable address translation */
	li.w    t1, 0x10 
	li.w    t2, 0x18 
	csrwr   t1, csr_crmd 

	add.w	a0, zero, zero		# a0 <-- boot_flags = 0
	add.w	ra, zero,zero
	b	board_init_f
END(_start)
