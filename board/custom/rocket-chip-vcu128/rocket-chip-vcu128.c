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

int board_fdt_blob_setup(void **fdtp)
{
	/* Use DTB passed from OpenSBI */
	*fdtp = (void *)(uintptr_t)gd->arch.firmware_fdt_addr;

	return 0;
}
