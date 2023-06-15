#include "lists.h"

/**
 * print_dlistint - output all the values stored in the list.
 * @h: memory address of the first node in the list
 * Return: size of the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t n;
	const dlistint_t *tmp;

	if (!h)
		return (0);

	tmp = h;
	for (n = 0; tmp; n++)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return (n);
}
