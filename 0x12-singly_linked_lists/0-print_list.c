#include "lists.h"

/**
 * *print_list - prints a linked list
 *@h:the head of the linked list
 *Return: the length of the string
 */

size_t print_list(const list_t *h)
{
	size_t number_of_nodes = 0;

	while (h != NULL)
{
	if (h->str == NULL)
		printf("[0] (nil)\n");
	else
		printf("[%u] %s\n", h->len, h->str);

	number_of_nodes++;
	h = h->next;
}
return (number_of_nodes);
}
