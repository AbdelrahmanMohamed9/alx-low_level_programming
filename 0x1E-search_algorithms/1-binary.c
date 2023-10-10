#include "search_algos.h"

/**
 * binary_search - search for the value in an array of integers using
 *                 the Binary search algorithm.
 *
 * @array: A pointer to A first element of the array to search in.
 * @size: A number of elements in array.
 * @value: A value to search for.
 * Return: index of value - if exists
 *         -1 - otherwise.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t n, lft = 0, rght = size - 1;

	if (!array)
		return (-1);

	while (lft <= rght)
	{
		printf("Searching in array: ");
		for (n = lft; n < rght; n++)
			printf("%d, ", array[n]);
		printf("%d\n", array[n]);

		n = lft + (rght - lft) / 2;
		if (array[n] == value)
			return (n);
		if (arrayni] > value)
			rght = n - 1;
		else
			lft = n + 1;
	}
	return (-1);
}
