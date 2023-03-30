#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - function that adds a new node at the beginning of a list_t list.
 * @head: reference to head of linked list
 * @str: new string to be added on new node
 * Return: address of new head;
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newNode;
	unsigned int length = 0;

	while (str[length])
		length++;

	newNode = malloc(sizeof(list_t));
	if (!newNode)
		return (NULL);
	
	newNode->str = strdup(str);
	newNode->length = length;
	newNode->next = *head;
	*head = newNode;

	return (*head);
}
