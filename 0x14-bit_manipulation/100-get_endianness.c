#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big-endian, 1 if little-endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endian_check = (char *)&num;

	/* If the least significant byte is non-zero, it's little-endian */
	return (*endian_check);
}

