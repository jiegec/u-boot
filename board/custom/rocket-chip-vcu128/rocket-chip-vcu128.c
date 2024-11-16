#include <asm/global_data.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	return 0;
}

int board_late_init(void)
{
	return 0;
}

void *board_fdt_blob_setup(int *err)
{
	// Use DTB passed from OpenSBI
	return (ulong *)(uintptr_t)gd->arch.firmware_fdt_addr;
}
