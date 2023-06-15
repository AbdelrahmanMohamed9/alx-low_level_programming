#include "lists.h"

/**
 * sum_dlistint - calculate the total sum of the values stored in the list.
 * @head: reference to the start node.
 * Return: total.
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;

	if (head)
	{
		while (head->prv)
			head = head->prv;

		while (head)
		{
			total += head->i;
			head = head->nxt;
		}
	}
	return (total);
}
