#include "main.h"

/**
 * _sqrt_helper - Helper function to calculate the square root using recursion.
 * @n: The number for which the square root is to be calculated.
 * @i: The current value to check as a possible square root.
 *
 * Return: The natural square root of the number.
 *         -1 if the number does not have a natural square root.
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number for which the square root is to be calculated.
 *
 * Return: The natural square root of the number.
 *         -1 if the number does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	return (_sqrt_helper(n, 1));
}

