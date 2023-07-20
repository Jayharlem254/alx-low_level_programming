#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - Finds the largest prime factor of a given number.
 * @num: The number for which to find the largest prime factor.
 *
 * Return: The largest prime factor of the number.
 */
long largest_prime_factor(long num)
{
    long largestFactor = -1;
    long i;

    /* Check for divisibility by 2 first */
    while (num % 2 == 0)
    {
        largestFactor = 2;
        num /= 2;
    }

    /* Check for divisibility by odd numbers starting from 3 */
    for (i = 3; i <= sqrt(num); i += 2)
    {
        while (num % i == 0)
        {
            largestFactor = i;
            num /= i;
        }
    }

    /* If the remaining number after the above loop is greater than 2,
       it must be a prime number itself */
    if (num > 2)
        largestFactor = num;

    return largestFactor;
}

int main(void)
{
    long number = 612852475143;
    long largest_prime = largest_prime_factor(number);

    printf("%ld\n", largest_prime);
    return 0;
}

