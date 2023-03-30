#include "lists.h"

/**
 * list_len - function that returns the number of elements in a linked list_t list.
 * @h: head of linked list
 * Return: number of elements in list_t
 */
size_t list_len(const list_t *h)
{
	size_t number_of_elements = 0;

	while (h)
	{
		number_of_elements++;
		h = h->next;
	}

	return (number_of_elements);
}
