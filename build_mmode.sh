#!/bin/sh
make CROSS_COMPILE=riscv64-linux-gnu- -j8 rocket-chip-vcu128_defconfig
make CROSS_COMPILE=riscv64-linux-gnu- -j8