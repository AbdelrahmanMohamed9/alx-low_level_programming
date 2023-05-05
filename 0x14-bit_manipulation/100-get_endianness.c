#include "main.h"

/**
 * get_endianness - endianness check
 * Return: when the end big 0 little 1
 */

int get_endianness(void)
{
	int mmk = 1;
	char *end = (char *)&mmk;
	int is_little_end = 0;

	while (*end)
	{
		is_little_end = 1;
		end++;
	}

	return (is_little_end);
}
