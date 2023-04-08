Copy code
#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, or 0 if there is an error
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i = 0;

	if (b == NULL)
	return (0);

	while (b[i] != '\0')
	{
	if (b[i] == '0' || b[i] == '1')
	{
		result = result * 2 + (b[i] - '0');
	}
		else
	{
		return (0);
	}

		i++;
	}

	return (result);
}
