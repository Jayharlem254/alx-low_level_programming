#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a linked list
 * @h: Pointer to a pointer to the head of the linked list
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current = *h;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;

		free(current);
		count++;

		if (next >= current)
		{
			break;
		}

		current = next;
	}

	*h = NULL;
	return (count);
}

