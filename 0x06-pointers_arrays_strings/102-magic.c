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

    /* Write your line of code here... */
    /* This line modifies the value of a[2] without directly using the variable 'a'
     * or modifying the variable 'p'.
     */
    int *p = &a[2];
    *(p + 5) = 98;

    /* The code below will print: a[2] = 98 */
    printf("a[2] = %d\n", a[2]);
    return (0);
}

