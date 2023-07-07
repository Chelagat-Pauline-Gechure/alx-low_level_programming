#include "hash_tables.h"

/**
 * hash_table_print - print the key & value pairs of hash table in order.
 * @ht: the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int array_index = 0;
	hash_node_t *ht_node;
	char *comma = "";

	if (!ht || !ht->array)
		return;

	putchar('{');
	while (array_index < ht->size)
	{
		ht_node = ((ht->array)[array_index]);
		while (ht_node)
		{
			printf("%s'%s': '%s'", comma, ht_node->key, ht_node->value);
			comma = ", ";
			ht_node = ht_node->next;
		}
		array_index++;
	}
	puts("}");
}
