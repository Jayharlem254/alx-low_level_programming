#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes the node at a given position
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to be deleted.
 * Return: 1 if the node was deleted successfully, or -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp, *current = *head;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	while (i < index - 1)
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
		i++;
	}

	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}

