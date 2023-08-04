#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string to which the source will be appended.
 * @src: The source string to be appended to the destination.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int i;

	/* Find the length of the destination string */
	while (dest[dest_len] != '\0')
		dest_len++;

	/* Append the source string to the destination */
	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len++] = src[i];

	/* Add a terminating null byte at the end */
	dest[dest_len] = '\0';

	return (dest);
}

