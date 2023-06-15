#include "lists.h"

/**
 * dlistint_len - Counts the Number of Elements in a linked dlistint_t list.
 * @h: The head of the dlistint_t list.
 *
 * Return: The Number of Elements in the dlistint_t list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t number_of_nodes = 0;

	while (h)
	{
		number_of_nodes++;
		h = h->next;
	}

	return (number_of_nodes);
}
