#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a 2D grid created by alloc_grid function.
 * @grid: Pointer to the grid to be freed.
 * @height: Height of the grid.
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

