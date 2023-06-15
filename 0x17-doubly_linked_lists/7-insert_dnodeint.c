#include "lists.h"

/**
 * insert_dnodeint_at_index - add a new node to the list at a specified index.
 * @h: first node of the list.
 * @idx: position of the new node in the list.
 * @n: data stored in the new node.
 * Return: memory location of the newly created node
 *	or NULL if the creation failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nw_node = NULL;
	dlistint_t *temp;
	unsigned int u;

	if (idx == 0)
		nw_node = add_dnodeint(h, n);
	else
	{
		temp = *h;
		if (temp)
			while (temp->prev)
				temp = temp->prev;
		for (u = 1; temp; u++)
		{
			if (u == idx)
			{
				if (!temp->next)
					nw_node = add_dnodeint_end(h, n);
				else
				{
					nw_node = malloc(sizeof(dlistint_t));
					if (nw_node)
					{
						nw_node->n = n;
						nw_node->next = temp->next;
						nw_node->prev = temp;
						temp->next->prev = nw_node;
						temp->next = nw_node;
					}
				}
				break;
			}
			temp = temp->next;
		}
	}

	return (nw_node);
}
