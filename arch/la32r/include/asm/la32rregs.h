/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 1994, 1995, 1996, 1997, 2000, 2001 by Ralf Baechle
 * Copyright (C) 2000 Silicon Graphics, Inc.
 * Copyright (C) 2000, 07 Loongson Technologies, Inc.
 */
#ifndef _ASM_LA32RREGS_H
#define _ASM_LA32RREGS_H

/*
 * The following macros are especially useful for __asm__
 * inline assembler.
 */
#ifndef __STR
#define __STR(x) #x
#endif
#ifndef STR
#define STR(x) __STR(x)
#endif

/*
 *  Configure language
 */
#ifdef __ASSEMBLY__
#define _ULCAST_
#else
#define _ULCAST_ (unsigned long)
#endif

#define csr_crmd 0x0
#define csr_prmd 0x1
#define csr_euen 0x2
#define csr_ectl 0x4
#define csr_estat 0x5
#define csr_era 0x6
#define csr_badv 0x7
#define csr_eentry 0xc
#define csr_tlbidx 0x10
#define csr_tlbehi 0x11
#define csr_tlbelo0 0x12
#define csr_tlbelo1 0x13
#define csr_asid 0x18
#define csr_pgdl 0x19
#define csr_pgdh 0x1a
#define csr_pgd 0x1b
#define csr_cpuid 0x20
#define csr_save0 0x30
#define csr_save1 0x31
#define csr_save2 0x32
#define csr_save3 0x33
#define csr_tid 0x40
#define csr_tcfg 0x41
#define csr_tval 0x42
#define csr_ticlr 0x44
#define csr_llbctl 0x60
#define csr_tlbrentry 0x88
#define csr_dmw0 0x180
#define csr_dmw1 0x181

#define ESTAT_SWI0 0x0001
#define ESTAT_SWI1 0x0002
#define ESTAT_HWI0 0x0004
#define ESTAT_HWI1 0x0008
#define ESTAT_HWI2 0x0010
#define ESTAT_HWI3 0x0020
#define ESTAT_HWI4 0x0040
#define ESTAT_HWI5 0x0080
#define ESTAT_HWI6 0x0100
#define ESTAT_HWI7 0x0200
#define ESTAT_TI 0x0800
#define ESTAT_IPI 0x1000

#define ESTAT_ECODE 0x003f0000
#define ESTAT_ESUBCODE 0x7fc00000

#define CRMD_PLV 0x0003
#define CRMD_IE 0x0004
#define CRMD_DA 0x0008
#define CRMD_PG 0x0010
#define CRMD_DATF 0x0020
#define CRMD_DATM 0x0080

#define PRMD_PPLV 0x0003
#define PRMD_PIE 0x0004

/*
 * FPU Status Register Values
 */
#define FPU_CSR_COND_S	23					/* $fcc0 */
#define FPU_CSR_COND	(_ULCAST_(1) << FPU_CSR_COND_S)

#define FPU_CSR_FS_S	24		/* flush denormalised results to 0 */
#define FPU_CSR_FS	(_ULCAST_(1) << FPU_CSR_FS_S)

#define FPU_CSR_CONDX_S	25					/* $fcc[7:1] */
#define FPU_CSR_CONDX	(_ULCAST_(127) << FPU_CSR_CONDX_S)
#define FPU_CSR_COND1_S	25					/* $fcc1 */
#define FPU_CSR_COND1	(_ULCAST_(1) << FPU_CSR_COND1_S)
#define FPU_CSR_COND2_S	26					/* $fcc2 */
#define FPU_CSR_COND2	(_ULCAST_(1) << FPU_CSR_COND2_S)
#define FPU_CSR_COND3_S	27					/* $fcc3 */
#define FPU_CSR_COND3	(_ULCAST_(1) << FPU_CSR_COND3_S)
#define FPU_CSR_COND4_S	28					/* $fcc4 */
#define FPU_CSR_COND4	(_ULCAST_(1) << FPU_CSR_COND4_S)
#define FPU_CSR_COND5_S	29					/* $fcc5 */
#define FPU_CSR_COND5	(_ULCAST_(1) << FPU_CSR_COND5_S)
#define FPU_CSR_COND6_S	30					/* $fcc6 */
#define FPU_CSR_COND6	(_ULCAST_(1) << FPU_CSR_COND6_S)
#define FPU_CSR_COND7_S	31					/* $fcc7 */
#define FPU_CSR_COND7	(_ULCAST_(1) << FPU_CSR_COND7_S)

/*
 * Bits 22:20 of the FPU Status Register will be read as 0,
 * and should be written as zero.
 */
#define FPU_CSR_RSVD	(_ULCAST_(7) << 20)

#define FPU_CSR_ABS2008	(_ULCAST_(1) << 19)
#define FPU_CSR_NAN2008	(_ULCAST_(1) << 18)

/*
 * X the exception cause indicator
 * E the exception enable
 * S the sticky/flag bit
*/
#define FPU_CSR_ALL_X	0x0003f000
#define FPU_CSR_UNI_X	0x00020000
#define FPU_CSR_INV_X	0x00010000
#define FPU_CSR_DIV_X	0x00008000
#define FPU_CSR_OVF_X	0x00004000
#define FPU_CSR_UDF_X	0x00002000
#define FPU_CSR_INE_X	0x00001000

#define FPU_CSR_ALL_E	0x00000f80
#define FPU_CSR_INV_E	0x00000800
#define FPU_CSR_DIV_E	0x00000400
#define FPU_CSR_OVF_E	0x00000200
#define FPU_CSR_UDF_E	0x00000100
#define FPU_CSR_INE_E	0x00000080

#define FPU_CSR_ALL_S	0x0000007c
#define FPU_CSR_INV_S	0x00000040
#define FPU_CSR_DIV_S	0x00000020
#define FPU_CSR_OVF_S	0x00000010
#define FPU_CSR_UDF_S	0x00000008
#define FPU_CSR_INE_S	0x00000004

/* Bits 0 and 1 of FPU Status Register specify the rounding mode */
#define FPU_CSR_RM	0x00000003
#define FPU_CSR_RN	0x0	/* nearest */
#define FPU_CSR_RZ	0x1	/* towards zero */
#define FPU_CSR_RU	0x2	/* towards +Infinity */
#define FPU_CSR_RD	0x3	/* towards -Infinity */


#endif /* _ASM_LA32RREGS_H */
