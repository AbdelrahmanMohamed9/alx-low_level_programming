#include "main.h"

/**
 *print_binary - Outputs binary representation of value.
 *@n: displayed the value in binary.
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
