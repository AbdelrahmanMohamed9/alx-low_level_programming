#include "hash_tables.h"

/**
 * key_index - That will generate a distributed index according to a given hash
 * @key: This is a key passed
 * @size: This is the size of the hash tables
 * Return: the key index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (key == NULL || size == 0)
		return (0);
	return (hash_djb2(key) % size);
}
