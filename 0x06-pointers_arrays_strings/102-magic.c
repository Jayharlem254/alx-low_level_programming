#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int n;
    int a[5];

    a[2] = 1024;
    n = sizeof(a) / sizeof(int);
    int *p;

    /* Write your line of code here... */
    *(p + 3) = 98;

    /* The code below will print: a[2] = 98 */
    printf("a[2] = %d\n", a[2]);
    return (0);
}

