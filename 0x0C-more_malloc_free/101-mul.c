#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _putchar(char c);

int is_digit(char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
    {
        char *error_message = "Error\n";
        while (*error_message)
        {
            _putchar(*error_message);
            error_message++;
        }
        exit(98);
    }

    char *num1 = argv[1];
    char *num2 = argv[2];

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int result_len = len1 + len2;
    int *result = malloc(result_len * sizeof(int));

    if (result == NULL)
    {
        char *error_message = "Error\n";
        while (*error_message)
        {
            _putchar(*error_message);
            error_message++;
        }
        exit(98);
    }

    int i;
    for (i = 0; i < result_len; i++)
        result[i] = 0;

    for (i = len1 - 1; i >= 0; i--)
    {
        int j;
        for (j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    int first_non_zero = 0;
    while (first_non_zero < result_len && result[first_non_zero] == 0)
    {
        first_non_zero++;
    }

    if (first_non_zero == result_len)
    {
        _putchar('0');
    }
    else
    {
        for (i = first_non_zero; i < result_len; i++)
        {
            _putchar(result[i] + '0');
        }
    }
    _putchar('\n');
    free(result);

    return 0;
}

int _putchar(char c)
{
    return write(1, &c, 1);
}

