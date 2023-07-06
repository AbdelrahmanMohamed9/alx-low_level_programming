#include "hash_tables.h"

/**
 * hash_table_create - That create a hash table
 * @size: This is a size of the array
 * Return: If an error occurs - a null pointer
 *	otherwise - a pointer to the
 *	newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	unsigned long int n;

	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (0);

	table->size = size;
	table->array = malloc(sizeof(hash_node_t *) * size);
	if (table->array == NULL)
		return (0);

	for (n = 0; n < size; n++)
		table->array[n] = NULL;

	return (table);
}
