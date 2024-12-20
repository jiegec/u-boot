#ifndef __TRIVIALMIPS_NSCSCC_CONFIG_H
#define __TRIVIALMIPS_NSCSCC_CONFIG_H

/* BootROM + MIG is pretty smart. DDR and Cache initialized */
#define CONFIG_SKIP_LOWLEVEL_INIT

/*--------------------------------------------
 * CPU configuration
 */
/* CPU Timer rate */
#define CONFIG_SYS_LOONGARCH_TIMER_FREQ	33 //Mhz

/* Cache Configuration */
#define CONFIG_SYS_MIPS_CACHE_MODE	CONF_CM_CACHABLE_NONCOHERENT

/*----------------------------------------------------------------------
 * Memory Layout
 */

/* SDRAM Configuration (for final code, data, stack, heap) */
#define CONFIG_SYS_SDRAM_BASE		0xa0000000
#define CONFIG_SYS_SDRAM_SIZE		0x08000000	/* 256 Mbytes */
#define CONFIG_SYS_INIT_SP_ADDR		\
	(CONFIG_SYS_SDRAM_BASE + CONFIG_SYS_SDRAM_SIZE - 0x1000)

#define CONFIG_SYS_MEMTEST_START    0xa0000000
#define CONFIG_SYS_MEMTEST_END      0xb0000000

#define CONFIG_SYS_MALLOC_LEN		(256 << 10)
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_LOAD_ADDR		0x90000000 /* default load address */

/*----------------------------------------------------------------------
 * Commands
 */
//#define CONFIG_SYS_LONGHELP		/* undef to save memory */
//#define CONFIG_CMDLINE_EDITING

/*------------------------------------------------------------
 * Console Configuration
 */
#define CONFIG_SYS_CBSIZE		1024 /* Console I/O Buffer Size   */
#define CONFIG_SYS_MAXARGS		16   /* max number of command args*/


// serial configuration
#define CONFIG_CONS_INDEX 1
#define CONFIG_SYS_NS16550_COM1 0x9fe001e0
#define CONFIG_SYS_NS16550_CLK 33000000
#define CONFIG_SYS_NS16550_IER 0


/* -------------------------------------------------
 * Environment
 */
//Disable persistent environment variable storage
#define CONFIG_ENV_IS_NOWHERE   1 


#define CONFIG_ENV_SIZE		0x4000
#define CONFIG_EXTRA_ENV_SETTINGS \
    "autoload=no\0" \
    "serverip=10.170.133.145\0" \
    "ipaddr=10.170.133.10\0" \
    "netmask=255.255.255.0\0" \
    "ethaddr=00:98:76:64:32:19\0"\
    "bootcmd=console=ttyS0,115200 rdinit=/init"



/* ---------------------------------------------------------------------
 * Board boot configuration
 */

#define CONFIG_TIMESTAMP	/* Print image info with timestamp */


/* Flash */
#define CONFIG_SYS_MAX_FLASH_BANKS_DETECT   1
#define CONFIG_SYS_MAX_FLASH_SECT           64


#endif /* __TRIVIALMIPS_NSCSCC_CONFIG_H */

