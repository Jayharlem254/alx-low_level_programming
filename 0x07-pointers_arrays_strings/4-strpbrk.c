#include "main.h"

/**
 * _strpbrk - Locates the first occurrence of any byte from accept in s.
 * @s: Pointer to the string to search.
 * @accept: Pointer to the set of acceptable bytes.
 *
 * Return: A pointer to the first occurrence of a byte from accept in s,
 *         or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		char *temp = accept;

		while (*temp != '\0')
		{
			if (*s == *temp)
				return (s);
			temp++;
		}

		s++;
	}

	return (NULL);
}

