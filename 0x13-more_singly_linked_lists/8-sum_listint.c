#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a
 * listint_t linked list
 * @head: pointer to head of list
 * Return: sum of list
 */
int sum_listint(listint_t *head)
{
	listint_t *current;

	register int summation = 0;

	if (!head)
		return (0);
	current = head;
	while (current)
	{
		summation += current->n;
		current = current->next;
	}
	return (summation);
}
