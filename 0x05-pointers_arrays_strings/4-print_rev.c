#include "main.h"

/**
 * print_rev - Prints a string in reverse, followed by a new line.
 * @s: Pointer to the string to be printed in reverse.
 */
void print_rev(char *s)
{
	int length = 0;

	/* Calculate the length of the string */
	while (s[length] != '\0')
		length++;

	/* Print the characters of the string in reverse order */
	for (length = length - 1; length >= 0; length--)
		_putchar(s[length]);

	_putchar('\n');
}

