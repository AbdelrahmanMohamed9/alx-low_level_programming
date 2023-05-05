#include "main.h"

/**
 * get_bit - Get value of the bit at the given index
 * @n: bit
 * @index: index that get value at indices start in 0
 *
 * Return: -1 in error if not error a value of bit at index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int f = 0;

	if (index >= (sizeof(unsigned long int) * 8))
	return (-1);

	while (f < index)
	{
		n = n >> 1;
		f++;
	}

	return (n & 1);
}
