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
		cr = cr->nxt;

	if (!cr)
		return (-1);
	if (*head == cr)
		*head = cr->nxt;
	if (cr->nxt)
		cr->nxt->prv = cr->prv;
	if (cr->prv)
		cr->prv->nxt = cr->nxt;

	free(cr);
	return (1);
}
