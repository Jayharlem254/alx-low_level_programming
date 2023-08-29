#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a linked list
 * @head: Pointer to the head of the linked list
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *next;

	while (current != NULL)
	{
		next = current->next;

		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		if (next >= current)
		{
			printf("-> [%p] %d\n", (void *)next, next->n);
			break;
		}

		current = next;
	}

	return (count);
}

