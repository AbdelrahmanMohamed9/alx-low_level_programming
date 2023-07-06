#include "hash_tables.h"

/**
 * shash_table_create - that will create a sorted hash table
 * @size: this is the size of new sorted hash table
 * Return: If an error occurs - a null pointer
 *	Otherwise - a pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hx;
	unsigned long int n;

	hx = malloc(sizeof(shash_table_t));
	if (hx == NULL)
		return (0);

	hx->size = size;
	hx->array = malloc(sizeof(shash_node_t *) * size);
	if (hx->array == NULL)
		return (0);

	for (n = 0; n < size; n++)
		hx->array[n] = NULL;
	hx->shead = NULL;
	hx->stail = NULL;

	return (hx);
}

/**
 * shash_table_set - That will add an element to a sorted hash table
 * @ht: This is pointer to the sorted hash table
 * @key: This is the key to add - cannot be an empty string
 * @value: This the value associated with key
 * Return: In case of failure - 0. Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *nw, *tp;
	char *vpy;
	unsigned long int n;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	vpy = strdup(value);
	if (vpy == NULL)
		return (0);

	n = key_index((const unsigned char *)key, ht->size);
	tp = ht->shead;
	while (tp)
	{
		if (strcmp(tp->key, key) == 0)
		{
			free(tp->value);
			tp->value = vpy;
			return (1);
		}
		tp = tp->snext;
	}

	nw = malloc(sizeof(shash_node_t));
	if (nw == NULL)
	{
		free(vpy);
		return (0);
	}

	nw->key = strdup(key);
	if (nw->key == NULL)
	{
		free(vpy);
		free(nw);
		return (0);
	}

	nw->value = vpy;
	nw->next = ht->array[n];
	ht->array[n] = nw;
	if (ht->shead == NULL)
	{
		nw->sprev = NULL;
		nw->snext = NULL;
		ht->shead = nw;
		ht->stail = nw;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		nw->sprev = NULL;
		nw->snext = ht->shead;
		ht->shead->sprev = nw;
		ht->shead = nw;
	}
	else
	{
		tp = ht->shead;
		while (tp->snext != NULL && strcmp(tp->snext->key, key) < 0)
			tp = tp->snext;
		nw->sprev = tp;
		nw->snext = tp->snext;
		if (tp->snext == NULL)
			ht->stail = nw;
		else
			tp->snext->sprev = nw;
		tp->snext = nw;
	}
	return (1);
}

/**
 * shash_table_get - That will retrieve the value associated with
 *	a key in a sorted hash table
 * @ht: This is the pointer to the sorted hash table
 * @key: This is the key to get the value of
 * Return: If the key cannot be found - a null pointer
 *	Otherwise - the value associated
 *	with the key in the hash table (ht).
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *nod;
	unsigned long int n;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	n = key_index((const unsigned char *)key, ht->size);
	if (n >= ht->size)
		return (0);

	nod = ht->shead;
	while (nod != NULL && strcmp(nod->key, key) != 0)
		nod = nod->snext;

	return ((nod == NULL) ? 0 : nod->value);
}

/**
 * shash_table_print - That will print a sorted hash table in order
 * @ht: This is the pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *nod;

	if (ht == NULL)
		return;

	nod = ht->shead;
	printf("{");
	while (nod != NULL)
	{
		printf("'%s': '%s'", nod->key, nod->value);
		nod = nod->snext;
		if (nod != NULL)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_print_rev -That will  print a sorted hash table in reverse order
 * @ht: This is the pointer to the sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *nod;

	if (ht == NULL)
		return;

	nod = ht->stail;
	printf("{");
	while (nod != NULL)
	{
		printf("'%s': '%s'", nod->key, nod->value);
		nod = nod->sprev;
		if (nod != NULL)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_delete - That will delete a sorted hash table
 * @ht: This is the pointer to the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *nod, *tp;

	if (ht == NULL)
		return;

	nod = ht->shead;
	while (nod)
	{
		tp = nod->snext;
		free(nod->key);
		free(nod->value);
		free(nod);
		nod = tp;
	}

	free(ht->array);
	free(ht);
}
