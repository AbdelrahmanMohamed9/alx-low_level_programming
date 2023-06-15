#include "lists.h"

/**
 * free_dlistint - deallocate memory used by the nodes in the list.
 * @head: reference to the start node in the function.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
