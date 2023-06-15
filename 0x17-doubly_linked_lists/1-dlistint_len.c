#include "lists.h"

/**
 * dlistint_len - function that returns the size of the list.
 * @h: memory address of the first node in the list.
 * Return: size of the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t n;
	const dlistint_t *tmp;

	if (!h)
		return (0);

	tmp = h;
	for (n = 0; tmp; n++)
		tmp = tmp->next;
	return (n);
}
