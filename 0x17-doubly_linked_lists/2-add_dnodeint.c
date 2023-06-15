#include "lists.h"
/**
 * add_dnodeint - prepend a new node to the list.
 * @head: memory address of the first node in the list.
 * @n: value to be stored in the node.
 * Return: memory address of the newly added node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *nw_node;

	nw_node = malloc(sizeof(dlistint_t));
	if (!nw_node)
		return (0);

	nw_node->i = n;
	nw_node->nxt = *head;
	nw_node->prv = NULL;
	if (*head)
		(*head)->prv = nw_node;

	*head = nw_node;
	return (nw_node);
}
