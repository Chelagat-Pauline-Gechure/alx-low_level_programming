#include "lists.h"

/**
 * add_dnodeint_end - Adds a newest_node node at the end of a dlistint_t list.
 * @head: A pointer to the head of the dlistint_t list.
 * @n: The Integer for the newest_node node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the Address of the newest_node node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newest_node, *last_node;

	newest_node = malloc(sizeof(dlistint_t));
	if (newest_node == NULL)
		return (NULL);

	newest_node->n = n;
	newest_node->next = NULL;

	if (*head == NULL)
	{
		newest_node->prev = NULL;
		*head = newest_node;
		return (newest_node);
	}

	last_node = *head;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = newest_node;
	newest_node->prev = last_node;

	return (newest_node);
}
