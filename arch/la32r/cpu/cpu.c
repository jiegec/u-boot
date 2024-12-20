// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, <wd@denx.de>
 */

#include <common.h>
#include <command.h>
#include <linux/compiler.h>
#include <asm/cache.h>
#include <asm/la32rregs.h>
#include <asm/reboot.h>

int do_reset(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	printf("resetting ...\n");

	printf("reset not supported yet\n");
	hang();
}

int arch_cpu_init(void)
{
	return 0;
}
