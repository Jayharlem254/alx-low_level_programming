#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Allocates a 2D array of integers.
 * @width: Width of the grid.
 * @height: Height of the grid.
 * Return: Pointer to the newly allocated 2D array, NULL on failure.
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **output;

	if (width <= 0 || height <= 0)
		return (NULL);

	output = malloc(sizeof(int *) * height);

	if (output == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		output[i] = malloc(sizeof(int) * width);

		if (output[i] == NULL)
		{
			free(output);
			for (j = 0; j <= height; j++)
				free(output[j]);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			output[i][j] = 0;
	}
	return (output);
}
