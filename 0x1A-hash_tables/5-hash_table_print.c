#include "hash_tables.h"

/**
 * hash_table_print - This will print a hash table
 * @ht: This is the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *nod;
	unsigned long int v = 0, n = 0;

	if (ht != NULL)
	{
		printf("{");
		for (n = 0; n < ht->size; n++)
		{
			nod = ht->array[n];
			while (nod != NULL)
			{
				if (v != 0)
					printf(", ");
				v = 1;
				printf("'%s': '%s'", nod->key, nod->value);
				nod = nod->next;
			}
		}
		printf("}\n");
	}
}
