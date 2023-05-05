#include "main.h"

/**
 *binary_to_uint - transforms the dual digit to the decimal digit
 *@b:the string containing the dual digit
 *Return: the digit after conversion
 */

unsigned int binary_to_uint(const char *p)
{
	int f = 0;
	unsigned int dv = 0;

	if (!p)
		return (0);

	while (p[f])
	{
		if (p[f] == '0')
			dv = dv * 2;
		else if (p[f] == '1')
			dv = dv * 2 + 1;
		else
			return (0);
		f++;
	}
	return (dv);
}
