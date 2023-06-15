#include "lists.h"

/**
 * sum_dlistint - adds all the data of dlistint_t list.
 * @head: The head of the dlistint_t list.
 *
 * Return: The sum of all the Data.
 */
int sum_dlistint(dlistint_t *head)
{
	int addition = 0;

	while (head)
	{
		addition += head->n;
		head = head->next;
	}

	return (addition);
}
