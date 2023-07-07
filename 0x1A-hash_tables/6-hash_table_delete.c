#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *ht_node, *tmp;
	unsigned long int index;

	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			ht_node = ht->array[index];
			while (ht_node != NULL)
			{
				tmp = ht_node->next;
				free(ht_node->key);
				free(ht_node->value);
				free(ht_node);
				ht_node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
