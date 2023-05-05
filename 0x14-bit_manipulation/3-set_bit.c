#include "main.h"

/**
 * set_bit - value of bit set at the given index to 1
 * @n:  pointer to bit.
 * @index: index that set value at indices start at 0
 * Return: If errror -1 if not error 1
 */

int set_bit(unsigned long int *n, unsigned int index)
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

	*n = (*n | mask);

	return (1);
}
