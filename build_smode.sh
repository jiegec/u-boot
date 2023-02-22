#!/bin/sh
make CROSS_COMPILE=riscv64-linux-gnu- -j8 rocket-chip-vcu128-smode_defconfig
make CROSS_COMPILE=riscv64-linux-gnu- -j8
size u-boot
ls -alh u-boot.bin
cd $HOME/opensbi
make CROSS_COMPILE=riscv64-linux-gnu- -j4 PLATFORM=rocket-chip-vcu128 FW_PAYLOAD_PATH=$HOME/u-boot/u-boot.bin