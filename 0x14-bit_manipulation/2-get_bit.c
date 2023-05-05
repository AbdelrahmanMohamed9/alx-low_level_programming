#include "main.h"

/**
 * get_bit - Get value of the bit at the given index
 * @f: bit
 * @dx: index that get value at indices start in 0
 *
 * Return: -1 in error if not error a value of bit at index
 */

int get_bit(unsigned long int f, unsigned int dx)
{
	if (dx >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((f & (1 << dx)) == 0)
		return (0);

	return (1);
}
