#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: Number of arguments.
 * @av: Array of arguments.
 * Return: Pointer to a new string containing concatenated arguments,
 *         or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	int total_length = 0;
	int i, j;
	char *concatenated;
	int position = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; av[i] != NULL; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			total_length++;
		total_length++;
	}

	concatenated = (char *)malloc(total_length + 1);
	if (concatenated == NULL)
		return (NULL);

	for (i = 0; av[i] != NULL; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			concatenated[position] = av[i][j];
			position++;
		}
		concatenated[position] = '\n';
		position++;
	}
	concatenated[position] = '\0';

	return (concatenated);
}

