#include "lists.h"


/**
 * delete_dnodeint_at_index - delete node at agiven index
 * @head: the head pointer
 * @index: the position
 * Return: 1(success) | -1(Failed)
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *prev, *temporary = *head;

	if (*head == NULL)
		return (-1);
	while (index != 0)
	{
		temporary = temporary->next;
		index--;
		if (temporary == NULL)
			return (-1);
	}
    
	if (temporary == *head)
	{
		*head = temporary->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		prev = temporary->prev;
		prev->next = temporary->next;
		if (temporary->next != NULL)
			temporary->next->prev = prev;
	}
	free(temporary);
	temporary = NULL;
	return (1);
}
