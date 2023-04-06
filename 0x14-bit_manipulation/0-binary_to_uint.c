#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: binary string to converts
 *
 * Return: positive number converted from a binary
 */
unsigned int binary_to_uint(const char *b)
{
	int num;
	unsigned int dec_value = 0;

	if (!b)
		return (0);
	for (num = 0; b[i]; i++)
	{
		if (b[num] < '0' || b[num] > '1')
			return (0);
		dec_value = 2 * dec_value + (b[num] - '0');
	}
	return (dec_value);
}
