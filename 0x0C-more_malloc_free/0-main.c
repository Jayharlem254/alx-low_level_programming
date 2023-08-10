#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *c;
    int *i;
    float *f;
    double *d;

    c = malloc_checked(sizeof(char) * 1024);
    printf("%p\n", (void *)c);

    if (c == NULL)
        return (98); /* Test the exit status within the program */

    i = malloc_checked(sizeof(int) * 402);
    printf("%p\n", (void *)i);

    if (i == NULL)
        return (98); /* Test the exit status within the program */

    f = malloc_checked(sizeof(float) * 100000000);
    printf("%p\n", (void *)f);

    if (f == NULL)
        return (98); /* Test the exit status within the program */

    d = malloc_checked(INT_MAX);
    printf("%p\n", (void *)d);

    if (d == NULL)
        return (98); /* Test the exit status within the program */

    free(c);
    free(i);
    free(f);
    free(d);

    return (0);
}

