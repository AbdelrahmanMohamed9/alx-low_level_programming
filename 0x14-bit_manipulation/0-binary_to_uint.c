#include "main.h"

/**
 *binary_to_uint - transforms the dual digit to the decimal digit
 *@b:the string containing the dual digit
 *Return: the digit after conversion
 */

unsigned int binary_to_uint(const char *b)
{
	int f = 0;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	while (b[f])
	{
		if (b[f] == '0')
			dec_val = dec_val * 2;
		else if (b[f] == '1')
			dec_val = dec_val * 2 + 1;
		else
			return (0);
		f++;
	}
	return (dec_val);
}
