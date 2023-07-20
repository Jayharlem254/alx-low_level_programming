#include "main.h"

/**
 * print_triangle - Prints a triangle of a given size.
 * @size: The size of the triangle.
 */
void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			_putchar(' '); /* Print leading spaces */
		}
		for (j = 0; j <= i; j++)
		{
			_putchar('#'); /* Print the triangle using '#' */
		}
		_putchar('\n'); /* Move to the next line */
	}
}
