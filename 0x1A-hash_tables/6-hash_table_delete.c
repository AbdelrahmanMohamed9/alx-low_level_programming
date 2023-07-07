#include "hash_tables.h"

/**
 * hash_table_delete - That will delete a hash table
 * @ht: this is the pointer to a hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *hd = ht;
	hash_node_t *nod, *tp;
	unsigned long int n;

	for (n = 0; n < ht->size; n++)
	{
		if (ht->array[n] != NULL)
		{
			nod = ht->array[n];
			while (nod != NULL)
			{
				tp = nod->next;
				free(nod->key);
				free(nod->value);
				free(nod);
				nod = tp;
			}
		}
	}
	free(hd->array);
	free(hd);
}
