#include "search_algos.h"

/**
 * _bsearch - search for the value in the sorted array
 *            of integers using binary search.
 *
 * @array: A pointer to the first element of the array to search.
 * @prev: A starting index of the [sub]array to search.
 * @next: A ending index of the [sub]array to search.
 * @value: A value to search for
 * Return: -1 - if the value is not present or the array is NULL
 *         the index where the value is located - otherwise.
 *
 * Description: Print A [sub]array being searched after each change.
 */
int _bsearch(int *array, size_t prev, size_t next, int value)
{
	size_t n;

	if (!array)
		return (-1);

	while (next >= prev)
	{
		printf("Searching in array: ");
		for (n = prev; n < next; n++)
			printf("%d, ", array[n]);
		printf("%d\n", array[n]);

		n = prev + (next - prev) / 2;
		if (array[n] == value)
			return (n);
		if (array[n] > value)
			next = n - 1;
		else
			prev = n + 1;
	}
	return (-1);
}

/**
 * exponential_search - search for the value in the sorted array
 *                      of integers using exponential search.
 *
 * @array: A pointer to the first element of the array to search.
 * @size: A number of elements in the array.
 * @value: A value to search for.
 * Return: -1 - If the value is not present or the array is NULL
 *         the index where the value is located - otherwise.
 *
 * Description: print a value every time it is compared in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t n = 0, nxt;

	if (!array)
		return (-1);

	if (array[0] != value)
		for (n = 1; n < size && array[n] <= value; n *= 2)
			printf("Value checked array[%ld] = [%d]\n", n, array[n]);

	next = n < size ? n : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", n / 2, nxt);
	return (_bsearch(array, n / 2, nxt, value));
}
