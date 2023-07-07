#include "hash_tables.h"

/**
 * hash_table_get - gets the value associated with
 *                  a key in the hash table.
 * @ht: ointer to the hash table.
 * @key: key to get the value of.
 *
 * Return: the value associated with the key in ht
 *  or NULL if the key cannot be matched..
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *ht_node;
	unsigned long int array_index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	array_index = key_index((const unsigned char *)key, ht->size);
	if (array_index >= ht->size)
		return (NULL);

	ht_node = ht->array[array_index];
	while (ht_node && strcmp(ht_node->key, key) != 0)
		ht_node = ht_node->next;

	return ((ht_node == NULL) ? NULL : ht_node->value);
}
