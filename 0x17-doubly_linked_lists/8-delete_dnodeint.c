#include "lists.h"

/**
 * delete_dnodeint_at_index - remove the node located at
 *	a specific index in the list
 * @head: reference to the start node in the function.
 * @index: insertion index.
 * Return: return 1 on success and -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cr;
	unsigned int nds;

	if (!head || !*head)
		return (-1);

	cr = *head;
	for (nds = 0; cr && nds < index; nds++)
		cr = cr->next;

	if (!cr)
		return (-1);
	if (*head == cr)
		*head = cr->next;
	if (cr->next)
		cr->next->prv = cr->prev;
	if (cr->prev)
		cr->prev->next = cr->next;

	free(cr);
	return (1);
}
