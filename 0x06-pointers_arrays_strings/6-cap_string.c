#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The input string to capitalize.
 *
 * Return: A pointer to the resulting capitalized string.
 */
char *cap_string(char *str)
{
	int i;
	int capitalize = 1;
	char *separators = " \t\n,;.!?\"(){}";

	for (i = 0; str[i]; i++)
	{
		if (capitalize && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 'a' + 'A';

		if (strchr(separators, str[i]) != NULL)
			capitalize = 1;
		else
			capitalize = 0;
	}

	return (str);
}

