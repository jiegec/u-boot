/* SPDX-License-Identifier: GPL-2.0 */
/*
 *
 * Some useful macros for LA32R assembler code
 *
 * Some of the routines below contain useless nops that will be optimized
 * away by gas in -O mode. These nops are however required to fill delay
 * slots in noreorder mode.
 */
#ifndef __ASM_ASM_H
#define __ASM_ASM_H


#ifndef CAT
#ifdef __STDC__
#define __CAT(str1, str2) str1##str2
#else
#define __CAT(str1, str2) str1/**/str2
#endif
#define CAT(str1, str2) __CAT(str1, str2)
#endif

/*
 * PIC specific declarations
 * Not used for the kernel but here seems to be the right place.
 */
#ifdef __PIC__
#define CPRESTORE(register)				\
		.cprestore register
#define CPADD(register)					\
		.cpadd	register
#define CPLOAD(register)				\
		.cpload register
#else
#define CPRESTORE(register)
#define CPADD(register)
#define CPLOAD(register)
#endif

#define ENTRY(symbol)					\
		.globl	symbol;				\
		.type	symbol, @function;		\
symbol:

/*
 * LEAF - declare leaf routine
 */
#define LEAF(symbol)					\
		.globl	symbol;				\
        .align  2;              \
		.type	symbol, @function;		\
symbol:

/*
 * NESTED - declare nested routine entry point
 */
#define NESTED(symbol, framesize, rpc)			\
		.globl	symbol;				\
		.align	2;				\
		.type	symbol, @function;		\
		.section .text.symbol, "x";

/*
 * END - mark end of function
 */
#define END(function)					\
		.size	function, .-function

/*
 * EXPORT - export definition of symbol
 */
#define EXPORT(symbol)					\
		.globl	symbol;				\
symbol:

/*
 * FEXPORT - export definition of a function symbol
 */
#define FEXPORT(symbol)					\
		.globl	symbol;				\
		.type	symbol, @function;		\
symbol:

/*
 * ABS - export absolute symbol
 */
#define ABS(symbol,value)				\
		.globl	symbol;				\
symbol		=	value


/*
 * Print formatted string
 */
#ifdef CONFIG_PRINTK
#define PRINT(string)					\
		.set	push;				\
		.set	reorder;			\
		PTR_LA	a0, 8f;				 \
		jal	printk;				\
		.set	pop;				\
		TEXT(string)
#else
#define PRINT(string)
#endif

#define TEXT(msg)					\
		.pushsection .data;			\
8:		.asciiz msg;				\
		.popsection;

/*
 * Build text tables
 */
#define TTABLE(string)					\
		.pushsection .text;			\
		.word	1f;				\
		.popsection				\
		.pushsection .data;			\
1:		.asciiz string;				\
		.popsection



#endif /* __ASM_ASM_H */
