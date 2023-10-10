#include "search_algos.h"

/**
 * interpolation_search - search for the value in an array of integers using
 *                        the Interpolation search algorithm.
 * @array: A pointer to A first element of the array to search in.
 * @size: A number of elements in array.
 * @value: A value to search for.
 * Return: index of the number - if value is in array
 *         -1 - otherwise.
 */
int interpolation_search(int *array, size_t size, int value)
{
	int ps, lw, hgh;
	double x;

	if (!array)
		return (-1);

	lw = 0;
	hgh = size - 1;
	while (size)
	{
		x = (double)(hgh - lw) / (array[hgh] - array[lw]);
		x *= (value - array[lw]);
		ps = (size_t)(lw + x);
		printf("Value checked array[%d]", ps);
		if (ps >= (int)size)
		{
			printf(" is out of range\n");
			break;
		}
		else
			printf(" = [%d]\n", array[ps]);

		if (array[ps] == value)
			return (ps);

		if (array[ps] < value)
			lw = ps + 1;
		else
			hgh = ps - 1;

		if (lw == hgh)
			break;
	}
	return (-1);
}
