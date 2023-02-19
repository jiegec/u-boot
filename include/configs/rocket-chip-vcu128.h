#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#define CONFIG_SYS_SDRAM_BASE 0x80000000
// do not collide with OpenSBI and U-Boot data
#define CONFIG_SYS_INIT_SP_ADDR 0x88000000
// loaded by OpenSBI at 0x80020000
#define CONFIG_SYS_LOAD_ADDR 0x80020000

#define CONFIG_SYS_BOOTM_LEN SZ_64M

#define CONFIG_STANDALONE_LOAD_ADDR 0x80200000

#define RISCV_MMODE_TIMERBASE 0x2000000
#define RISCV_MMODE_TIMER_FREQ 1000000

#define CONFIG_ENV_IS_NOWHERE 1

#define CONFIG_EXTRA_ENV_SETTINGS                                              \
  "autoload=no\0"                                                              \
  "serverip=10.0.0.1\0"                                                        \
  "ipaddr=10.0.0.2\0"                                                          \
  "netmask=255.255.255.0\0"                                                    \
  "boot_linux=tftpboot 0x90000000 10.0.0.1:image.itb;setenv initrd_high "      \
  "0x92000000;setenv fdt_high 0x91000000;bootm 0x90000000\0"

#define CONFIG_TIMESTAMP

#endif /* __CONFIG_H */
