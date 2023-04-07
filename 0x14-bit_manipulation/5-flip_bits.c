#include "main.h"

/**
 * flip_bits - Returns the number of bits to flip
	to get one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x = n ^ m;
	unsigned int count = 0;

	while (x)
		{
		count++;
		x &= (x - 1);
		}

	return (count);
}
