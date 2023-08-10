#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
	int i, j, len1, len2, carry, digit1, digit2, result_len;
	int *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	len1 = len2 = 0;
	while (argv[1][len1] != '\0')
		len1++;
	while (argv[2][len2] != '\0')
		len2++;

	result_len = len1 + len2;
	result = calloc(result_len, sizeof(int));

	if (result == NULL)
	{
		printf("Error\n");
		return (98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		digit1 = argv[1][i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = argv[2][j] - '0';
			result[i + j + 1] += carry + (digit1 * digit2);
			carry = result[i + j + 1] / 10;
			result[i + j + 1] %= 10;
		}
		result[i + j + 1] += carry;
	}

	i = 0;

	while (i < result_len - 1 && result[i] == 0)
		i++;

	for (; i < result_len; i++)
		putchar(result[i] + '0');
	putchar('\n');

	free(result);
	return (0);
}

