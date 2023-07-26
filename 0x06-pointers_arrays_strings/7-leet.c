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
	char *leet_chars = "aeotlAEOTL";
	char *leet_codes = "4307143071";

	while (*ptr)
	{
		char *ch = leet_chars;
		char *code = leet_codes;

		for (; *ch && *ptr != *ch; ch++, code++)
			;

		if (*ptr == *ch)
			*ptr = *code;

		ptr++;
	}

	return (str);
}

