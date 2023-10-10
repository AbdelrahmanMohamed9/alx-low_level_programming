#include "search_algos.h"

/**
 * linear_search - search for a value in an array of integers using
 *                 the Linear search algorithm.
 *
 * @array: A pointer to A first element of the array to search in.
 * @size: A number of elements in array.
 * @value: The value to search for.
 * Return: First index where value is located - if value is present
 *         -1 - if value is not present in array or if array is NULL.
 */
int linear_search(int *array, size_t size, int value)
{
	int n;

	if (!array)
		return (-1);

	for (n = 0; n < (int)size; n++)
	{
		printf("Value checked array[%u] = [%d]\n", n, array[n]);
		if (value == array[n])
			return (n);
	}
	return (-1);
}
