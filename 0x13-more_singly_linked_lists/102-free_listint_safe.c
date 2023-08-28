#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: A pointer to a pointer to the head of the list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current = *h;
	listint_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		count++;

		if (next_node >= current)
		{
			*h = NULL;
			exit(98);
		}

		current = next_node;
	}

	*h = NULL;
	return (count);
}

