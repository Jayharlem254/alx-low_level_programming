#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - Finds the beginning of a loop in a linked list
 * @head: Pointer to the head of the linked list
 * Return: Address of the node where the loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			printf("Loop starts at [%p] %d\n", (void *)slow, slow->n);
			return (slow);
		}
	}

	return (NULL);
}

