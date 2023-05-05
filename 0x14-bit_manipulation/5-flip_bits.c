#include "main.h"

/**
 * flip_bits - Count num of bits that need to be flipped
 * @n: a num
 * @m: a num that flip n
 *
 * Return: a num of bits to get from n to m
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mma = n ^ m, bts = 0;
	int f;

	for (f = 0; f < sizeof(unsigned long int) * 8; f++)
	{
		if (mma & (1UL << f))
		bts++;
	}

	return (bts);
}
