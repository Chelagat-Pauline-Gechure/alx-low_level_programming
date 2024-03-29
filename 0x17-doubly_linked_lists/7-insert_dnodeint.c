#include "lists.h"

/**
* insert_dnodeint_at_index - Inserts a new node in a dlistint_t
* list at a given position.
* @h: A pointer to the head of the dlistint_t list.
* @idx: The position to insert the new node.
* @n: The integer for the new node to contain.
*
* Return: If the function fails - NULL.
* Otherwise - the address of the new node.
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *temporary = *h, *new_node;

if (idx == 0)
return (add_dnodeint(h, n));

for (; idx != 1; idx--)
{
temporary = temporary->next;
if (temporary == NULL)
return (NULL);
}

if (temporary->next == NULL)
return (add_dnodeint_end(h, n));

new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->prev = temporary;
new_node->next = temporary->next;
temporary->next->prev = new_node;
temporary->next = new_node;

return (new_node);
}
