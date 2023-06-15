#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - print elements of doubly linked list
 * @h: linked list
 *
 * Return: number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t number_of_nodes = 0;
	const dlistint_t *current_node = h;

	while (current_node != NULL)
	{
		printf("%i\n", current_node->n);
		current_node = current_node->next;
		number_of_nodes++;
	}

	return (number_of_nodes);
}
