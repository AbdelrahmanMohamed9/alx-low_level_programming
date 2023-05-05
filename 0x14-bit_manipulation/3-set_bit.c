#include "main.h"

/**
 * set_bit - value of bit set at the given index to 1
 * @f:  pointer to bit.
 * @dx: index that set value at indices start at 0
 * Return: If errror -1 if not error 1
 */

int set_bit(unsigned long int *f, unsigned int dx)
{
	if (dx >= (sizeof(unsigned long int) * 8))
		return (-1);

	*f ^= (1 << dx);

	return (1);
}
