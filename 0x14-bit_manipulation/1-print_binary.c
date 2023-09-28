#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int bit_count = sizeof(unsigned long int) * 8;
	int bit_index;
	int printed = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (bit_index = bit_count - 1; bit_index >= 0; bit_index--)
	{
		if ((n >> bit_index) & 1)
		{
			_putchar('1');
			printed = 1;
		}
		else if (printed)
		{
			_putchar('0');
		}
	}
}

