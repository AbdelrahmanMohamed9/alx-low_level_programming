#include "hash_tables.h"

/**
 * hash_table_delete - That will delete a hash table
 * @ht: this is the pointer to a hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *nod, *tp;
	unsigned long int n;

	if (ht == NULL)
		return;

	for (n = 0; n < ht->size; n++)
	{
		nod = ht->array[n];
		while ((tp = nod) != NULL)
		{
			nod = nod->next;
			free(tp->key);
			free(tp->value);
			free(tp);
		}
	}
	free(ht->array);
	free(ht);
}
