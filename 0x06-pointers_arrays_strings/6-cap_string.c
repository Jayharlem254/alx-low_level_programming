#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The input string to be capitalized
 *
 * Return: Pointer to the modified string
 */

char *cap_string(char *str)
{
	int i, j;
	const char sp[13] = {' ', '\t', '\n', ',', ';',
			    '.', '!', '?', '"', '(', ')', '{', '}'};

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;

	for (i = 1; str[i] != '\0'; i++)
	{
		for (j = 0; j < 13; j++)
		{
			if (str[i - 1] == sp[j] && (str[i] >= 'a' && str[i] <= 'z'))
			{
				str[i] = str[i] - 32;
			}
		}
	}
	return (str);
}

