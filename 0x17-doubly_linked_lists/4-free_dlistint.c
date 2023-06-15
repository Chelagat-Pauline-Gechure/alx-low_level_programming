#include "lists.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: Pointer to first node in the list.
 *
 * Return: Nothing.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node = head;
	dlistint_t *prev_node = head;

	if (!head)
		return;

	while (current_node->next)
	{
		current_node = current_node->next;
		free(prev_node);
		prev_node = current_node;
	}
	free(current_node);
}
