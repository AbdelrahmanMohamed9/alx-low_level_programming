#include "search_algos.h"
#include <math.h>

/**
 * jump_search - search for the value in an array of integers using
 *               the Jump search algorithm.
 *
 * @array: the pointer to the first element of the array to search in.
 * @size: a number of elements in array.
 * @value: a value to search for.
 * Return: Index of the number - if present in array
 *         -1 - otherwise.
 */
int jump_search(int *array, size_t size, int value)
{
	int n, v, x, tp;

	if (!array || size == 0)
		return (-1);

	v = (int)sqrt((double)size);
	n = x = tp = 0;
	for (; n < (int)size && array[n] < value; x++, tmp = n, n = v * x)
	{
		printf("Value checked array[%d] = [%d]\n", n, array[n]);
		if (array[n] == value)
			return (n);
	}

	printf("Value found between indexes [%d] and [%d]\n", tp, n);
	for (; tp <= n && tp < (int)size; tp++)
	{
		printf("Value checked array[%d] = [%d]\n", tp, array[tp]);
		if (array[tp] == value)
			return (tp);
	}
	return (-1);
}
