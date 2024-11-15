#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#define CONFIG_SYS_SDRAM_BASE 0x80000000

#define RISCV_MMODE_TIMERBASE 0x2000000
#define RISCV_MMODE_TIMER_FREQ 1000000

#define CONFIG_ENV_IS_NOWHERE 1

#define CONFIG_EXTRA_ENV_SETTINGS                                              \
  "autoload=no\0"                                                              \
  "serverip=10.0.0.1\0"                                                        \
  "ipaddr=10.0.0.2\0"                                                          \
  "netmask=255.255.255.0\0"                                                    \
  "boot_single=tftpboot 0x80100000 10.0.0.1:image-single-core.itb;bootm "      \
  "0x80100000\0"                                                               \
  "boot_dual=tftpboot 0x80100000 10.0.0.1:image-dual-core.itb;bootm "          \
  "0x80100000\0"

#define CONFIG_TIMESTAMP

#endif /* __CONFIG_H */
