#include "lists.h"

/**
 * get_dnodeint_at_index - retrieve the node at a specific index in the list.
 * @head: head pointer.
 * @index: ndex of the node.
 * Return: node located at a specific index in the list.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int n;
	dlistint_t *temp = NULL;

	if (!head)
		return (0);

	temp = head;
	for (n = 0; temp; n++)
	{
		if (index == 0)
			return (temp);

		temp = temp->next;
		if (n == (index - 1) && index != 0)
			return (temp);
	}
	return (0);
}
