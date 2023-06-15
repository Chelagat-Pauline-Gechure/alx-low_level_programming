#include "lists.h"

/**
 * add_dnodeint - adds new node at the beginning of a doubly linked list
 * @head: Pointer to first node in the doubly linked list.
 * @n: Data for the new node.
 *
 * Return: Pointer to the newly added node.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newest_node;

	newest_node = malloc(sizeof(dlistint_t));
	if (!newest_node)
		return (NULL);

	newest_node->n = n;
	newest_node->next = *head;
	newest_node->prev = NULL;

	if (*head)
		(*head)->prev = newest_node;
	*head = newest_node;

	return (newest_node);
}
