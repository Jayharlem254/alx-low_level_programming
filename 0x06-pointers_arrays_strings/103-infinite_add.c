#include "main.h"
#include <string.h>

/**
 * reverse_string - Reverses a string
 * @str: The input string to be reversed
 */
void reverse_string(char *str)
{
	int start = 0;
	int end = strlen(str) - 1;
	char temp;

	while (start < end)
	{
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
		start++;
		end--;
	}
}

/**
 * add_digit - Adds two digits taking into account carry
 * @num1: The first digit
 * @num2: The second digit
 * @carry: Pointer to carry
 * Return: The sum of num1 and num2
 */
int add_digit(int num1, int num2, int *carry)
{
	int sum = num1 + num2 + *carry;

	*carry = sum / 10;
	return (sum % 10);
}

/**
 * infinite_add - Adds two numbers
 * @n1: The first number
 * @n2: The second number
 * @r: The buffer to store the result
 * @size_r: The buffer size
 *
 * Return: Pointer to the result, or 0 if the result cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, max_len, carry = 0, sum;
	int i;

	len1 = strlen(n1);
	len2 = strlen(n2);
	max_len = len1 > len2 ? len1 : len2;

	if (max_len + 1 > size_r)
		return (0);

	r[max_len + 1] = '\0';
	reverse_string(n1);
	reverse_string(n2);

	for (i = 0; i < max_len; i++)
	{
		int num1 = i < len1 ? n1[i] - '0' : 0;
		int num2 = i < len2 ? n2[i] - '0' : 0;

		sum = add_digit(num1, num2, &carry);
		r[i] = sum + '0';
	}

	if (carry)
	{
		r[max_len] = carry + '0';
		return (r);
	}
	else
	{
		r[max_len] = '\0';
		reverse_string(r);
		return (r);
	}
}

