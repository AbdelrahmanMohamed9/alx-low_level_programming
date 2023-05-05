#include "main.h"

/**
 *print_binary - Outputs binary representation of value.
 *@n: displayed the value in binary.
 */

void print_binary(unsigned long int n)
{
	int f;
	int bits = sizeof(unsigned long int) * 8;

	for (f = bits - 1; f >= 0; f--)
	{
		if ((n >> f) & 1)
		break;
	}

	while (f >= 0)
	{
		_putchar((n >> f) & 1 ? '1' : '0');
		f--;
	}
}
