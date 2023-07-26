#include "main.h"

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number to add.
 * @n2: The second number to add.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 *
 * Return: A pointer to the result, or 0 if the result cannot be stored in r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, carry, i, j;

	len1 = len2 = carry = 0;

	while (n1[len1 + 1])
		len1++;
	while (n2[len2 + 1])
		len2++;

	if (len1 >= size_r || len2 >= size_r)
		return (0);

	r[size_r - 1] = '\0';
	i = len1;
	j = len2;
	size_r--;

	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			carry += n1[i--] - '0';
		if (j >= 0)
			carry += n2[j--] - '0';

		r[size_r--] = (carry % 10) + '0';
		carry /= 10;
	}

	if (carry && size_r >= 0)
	{
		r[size_r--] = carry + '0';
		if (size_r < 0)
			return (0);
	}

	return (r + size_r + 1);
}

