#include "main.h"

/**
 * clear_bit - puts value of bit in given index to 0
 * @n: pointer to bit.
 * @index: index that put value in indices start at 0.
 * Return: -1 in error , if not error 1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	int f = 0;
	unsigned long int mask = 1;

	if (index >= (sizeof(unsigned long int) * 8))
	return (-1);

	while (f < index)
	{
		mask = mask << 1;
		f++;
	}

	*n = (*n & ~mask);

	return (1);
}
