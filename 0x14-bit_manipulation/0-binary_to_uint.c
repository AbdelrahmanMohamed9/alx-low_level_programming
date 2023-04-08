#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, or 0 if there is an error
 */
unsigned int binary_to_uint(const char *b)
{
	int m;
	unsigned int x = 0;

	if (!b)
		return (0);
	for (m = 0; b[m]; m++)
	{
		if (b[m] < '0' || b[m] > '1')
			return (0);
		x = 2 * x + (b[m] - '0');
	}
	return (x);
}
