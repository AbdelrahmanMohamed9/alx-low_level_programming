#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct dlistint_s -that is the doubly linked list.
 * @i:this is an integer.
 * @prv: maintain a link to the node that comes before it.
 * @nxt: store a reference to the following node
 *
 *Description: node structure implementation for a doubly
 *	linked list in the project
 */
typedef struct dlistint_s
{
	int i;
	struct dlistint_s *prv;
	struct dlistint_s *nxt;
} dlistint_t;

size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int i);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int i);
void free_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
int sum_dlistint(dlistint_t *head);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int i);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

#endif /* _LISTS_H_ */
