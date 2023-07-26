#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 cipher
 * @s: The input string to be encoded
 *
 * Return: Pointer to the encoded string
 */
char *rot13(char *s)
{
	int i;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i]; i++)
	{
		char *ptr = alpha;
		char *ptr_rot = rot13;

		while (*ptr)
		{
			if (*ptr == s[i])
			{
				s[i] = *ptr_rot;
				break;
			}

			ptr++;
			ptr_rot++;
		}
	}

	return (s);
}

