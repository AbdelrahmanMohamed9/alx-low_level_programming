#include "hash_tables.h"

/**
 * hash_table_set -That will add an element to the hash table
 * @ht:this is the  pointer to the hash table
 * @key:this is the pointer to the key
 * @value:this is value to add
 * Return: this if success return 1 otherwise 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long n;
	hash_node_t *nw_nod;

	if (ht  == NULL || key == NULL || value == NULL)
		return (0);

	n = key_index((const unsigned char *)key, ht->size);
	if (ht->array[n] != NULL && strcmp(ht->array[n]->key, key) == 0)
	{
		ht->array[n]->value = strdup(value);
		return (1);
	}

	nw_nod = malloc(sizeof(hash_node_t));
	if (nw_nod == NULL)
		return (0);

	nw_nod->key = strdup(key);
	nw_nod->value = strdup(value);
	nw_nod->next = ht->array[n];
	ht->array[n] = nw_nod;
	return (1);
}
