#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The input string to capitalize.
 *
 * Return: A pointer to the resulting string.
 */
char *cap_string(char *str)
{
	char *ptr = str;
	int capitalize_next = 1;

	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			if (capitalize_next)
			{
				*ptr = *ptr - ('a' - 'A');
				capitalize_next = 0;
			}
		}
		else if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' ||
			 *ptr == ',' || *ptr == ';' || *ptr == '.' ||
			 *ptr == '!' || *ptr == '?' || *ptr == '"' ||
			 *ptr == '(' || *ptr == ')' || *ptr == '{' ||
			 *ptr == '}')
		{
			capitalize_next = 1;
		}

		ptr++;
	}

	return (str);
}

