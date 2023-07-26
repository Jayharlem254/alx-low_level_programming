#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @str: The input string to encode.
 *
 * Return: A pointer to the resulting encoded string.
 */
char *leet(char *str)
{
	char *ptr = str;
	char *letters = "aeotlAEOTL";
	char *leet_code = "4307143071";

	while (*ptr != '\0')
	{
		char *letter = letters;
		char *code = leet_code;
		int found = 0;

		while (*letter != '\0')
		{
			if (*ptr == *letter)
			{
				*ptr = *code;
				found = 1;
				break;
			}
			letter++;
			code++;
		}

		if (!found)
			ptr++;
		else
			ptr++;
	}

	return (str);
}

