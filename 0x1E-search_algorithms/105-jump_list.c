#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Searches for THE value in an array of.
 * integers Using A Jump search algorithm.
 *
 * @list: Input list.
 * @size: Size of A array.
 * @value: Value to search in.
 * Return: Index of A number.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t indx, x, c;
	listint_t *prev;

	if (list == NULL || size == 0)
		return (NULL);

	c = (size_t)sqrt((double)size);
	indx = 0;
	x = 0;

	do {
		prev = list;
		x++;
		indx = x * c;

		while (list->next && list->indx < indx)
			list = list->next;

		if (list->next == NULL && indx != list->indx)
			indx = list->indx;

		printf("Value checked at index [%d] = [%d]\n", (int)indx, list->n);

	} while (indx < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->indx, (int)list->indx);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->indx, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
