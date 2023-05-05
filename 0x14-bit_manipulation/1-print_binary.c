#include "main.h"

/**
 *print_binary - Outputs binary representation of value.
 *@f: displayed the value in binary.
 */

void print_binary(unsigned long int f)
{
	if (f > 1)
		print_binary(f >> 1);

	_putchar((f & 1) + '0');
}
