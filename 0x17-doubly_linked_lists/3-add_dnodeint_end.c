#include "lists.h"

/**
 * add_dnodeint_end - append a new node to the list.
 * @head: head pointer.
 * @n: integer to be inserted.
 * Return: memory location of the newly created node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nw_node;
	dlistint_t *temp;

	nw_node = malloc(sizeof(dlistint_t));
	if (!nw_node)
		return (0);

	nw_node->i = n;
	nw_node->nxt = NULL;
	if (!*head)
	{
		*head = nw_node;
		nw_node->prv = NULL;
	}
	else
	{
		temp = *head;
		while (temp->nxt)
			temp = temp->nxt;
		temp->nxt = nw_node;
		nw_node->prv = temp;
	}
	return (nw_node);
}
