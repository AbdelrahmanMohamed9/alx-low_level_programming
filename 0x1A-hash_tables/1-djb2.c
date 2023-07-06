#include "hash_tables.h"

/**
 * hash_djb2 - That will generate a random number through
 * a given string (hash number)
 * @str: This is the string
 * Return: the hash number
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int has = 5381;
	int v;

	while ((v = *str++))
		has = ((has << 5) + has) + v; /* has * 33 + v */

	return (has);
}
