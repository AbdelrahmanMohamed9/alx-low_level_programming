#include "search_algos.h"

/**
 * _rsearch - search recursively for the value in an array of
 *            integers using the Binary search algorithm.
 *
 * @array: A pointer to the first element of the array to search in.
 * @size: A number of elements in array.
 * @value: A value to search for.
 * Return: Index of value - if exists
 *         -1 - otherwise.
 */
int _rsearch(int *array, size_t size, int value)
{
	size_t n, md = size / 2;

	if (!array || size == 0)
		return (-1);

	printf("Searching in array");
	for (n = 0; n < size; n++)
		printf("%s %d", (n == 0) ? ":" : ",", array[n]);
	printf("\n");

	if (md && size % 2 == 0)
		md--;

	if (value == array[md])
	{
		if (md > 0)
			return (_rsearch(array, md + 1, value));
		return ((int)md);
	}

	if (value < array[md])
		return (_rsearch(array, md + 1, value));

	md++;
	return (_rsearch(array + md, size - md, value) + md);
}

/**
 * advanced_binary - wrap _rsearch and validate a index returned.
 *
 * @array: A pointer to the first element of the array to search in.
 * @size: A number of elements in array.
 * @value: A value to search for.
 * Return: Index of value - if checks passed
 *         -1 - otherwise.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int n;

	n = _rsearch(array, size, value);
	if (n >= 0 && array[n] != value)
		return (-1);

	return (n);
}
