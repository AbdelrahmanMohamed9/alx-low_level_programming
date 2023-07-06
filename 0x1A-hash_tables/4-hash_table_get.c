#include "hash_tables.h"

/**
 * hash_table_get - This will retrieve a value associated with a key
 * @ht: this is the hash table you want to look into
 * @key: this is the key sought
 * Return: The value linked to the element, or else a null pointer.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *nod;
	unsigned long int n;

	if (key == NULL || ht == NULL)
		return (0);

	n = key_index((const unsigned char *)key, ht->size);
	nod = ht->array[n];
	for (; nod != NULL; nod = nod->next)
		if (strcmp(nod->key, key) == 0)
			return (nod->value);

	return (0);
}
