/* 0-putchar.c */

#include <stdio.h>
#include "unistd.h"  /* This should provide the declaration of the write function. */

int _putchar(char c);  /* Declaration of _putchar function. */

int main()
{
    _putchar('_');
    _putchar('p');
    _putchar('u');
    _putchar('t');
    _putchar('c');
    _putchar('h');
    _putchar('a');
    _putchar('r');
    _putchar('\n');

    return 0;
}

