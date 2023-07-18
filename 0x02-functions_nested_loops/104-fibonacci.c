#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the first 98 Fibonacci numbers separated by commas
 * starting with 1 and 2, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    unsigned long int a, b, c, next;
    int count;

    a = 1;
    b = 2;
    count = 2;

    printf("%lu, %lu", a, b);

    while (count < 98)
    {
        next = a + b;
        printf(", %lu", next);

        a = b;
        b = next;
        count++;
    }

    printf("\n");
    return 0;
}

