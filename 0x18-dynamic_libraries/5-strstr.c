#include <stddef.h>
#include "main.h"

/**
 * _strstr - Locates the first occurrence of the substring needle in haystack.
 * @haystack: Pointer to the string to search.
 * @needle: Pointer to the substring to find.
 *
 * Return: A pointer to the beginning of the located substring,
 *         or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *h = haystack;
		char *n = needle;

		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
			return (haystack);

		haystack++;
	}

	return (NULL);
}

