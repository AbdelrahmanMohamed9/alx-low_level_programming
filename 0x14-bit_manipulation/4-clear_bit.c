#include "main.h"

/**
 * clear_bit - puts value of bit in given index to 0
 * @f: pointer to bit.
 * @dx: index that put value in indices start at 0.
 * Return: -1 in error , if not error 1
 */

int clear_bit(unsigned long int *f, unsigned int dx)
{
	if (dx >= (sizeof(unsigned long int) * 8))
		return (-1);

	*f &= ~(1 << dx);

	return (1);
}
