#include "main.h"

/**
 * flip_bits - Count num of bits that need to be flipped
 * @f: a num
 * @y: a num that flip n
 *
 * Return: a num of bits to get from n to m
 */

unsigned int flip_bits(unsigned long int f, unsigned long int y)
{
	unsigned long int wwe = f ^ y, bbit = 0;

	while (wwe > 0)
	{
		bbit += (wwe & 1);
		wwe >>= 1;
	}

	return (bbit);
}
