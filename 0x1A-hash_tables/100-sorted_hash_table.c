#include "hash_tables.h"

/**
 * hash_table_create - creates a new sorted hash table
 * @size: -size of the sorted array
 *
 * Return: pointer to the newly hash table or NULL if error occurs
 */
shash_table_t *shash_table_create(unsigned long int size)
{	
	shash_table_t *hash_table;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	hash_table = malloc(sizeof(shash_table_t));
	if (hash_table == NULL)
		return (NULL);  /* Unable to allocate memory for hash table */

	hash_table->size = size;
	hash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;
	hash_table->shead = NULL;
	hash_table->stail = NULL;
	return (hash_table);
}

/**
 * hash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table to add or update the key/value to.
 * @key: The key. Must not be an empty string.
 * @value: The value associated with the key. Must be duplicated.
 *
 * Return: 1 if the operation succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current_node, *prev_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	
	index = key_index((unsigned char *)key, ht->size);
	current_node = ht->array[index];
	prev_node = NULL;

	while (current_node != NULL && strcmp(current_node->key, key) < 0)
	{
		prev_node = current_node;
		current_node = current_node->snext;
	}

	if (current_node != NULL && strcmp(current_node->key, key) == 0)
	{
		free(current_node->value);
		current_node->value = strdup(value);
		return current_node->value != NULL;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	new_node->next = current_node;
	new_node->sprev = prev_node;
	new_node->snext = current_node;

	if (prev_node != NULL)
		prev_node->snext = new_node;
	else
		ht->shead = new_node;

	if (current_node != NULL)
		current_node->sprev = new_node;
	else
		ht->stail = new_node;

	ht->array[index] = new_node;

	return (1);
}

/**
 * shash_table_get - gets the value associated with
 *                  a key in the hash table.
 * @ht: ointer to the hash table.
 * @key: key to get the value of.
 *
 * Return: the value associated with the key in ht
 *  or NULL if the key cannot be matched..
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *ht_node;
	unsigned long int array_index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	array_index = key_index((const unsigned char *)key, ht->size);
	if (array_index >= ht->size)
		return (NULL);

	ht_node = ht->shead;
	while (ht_node && strcmp(ht_node->key, key) != 0)
		ht_node = ht_node->snext;

	return ((ht_node == NULL) ? NULL : ht_node->value);
}

/**
 * shash_table_print - print the key & value pairs of hash table in order.
 * @ht: the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned long int array_index = 0;
	shash_node_t *ht_node;
	char *comma = "";

	if (!ht || !ht->array)
		return;

	putchar('{');
	while (array_index < ht->size)
	{
		ht_node = ht->shead;
		while (ht_node)
		{
			printf("%s'%s': '%s'", comma, ht_node->key, ht_node->value);
			comma = ", ";
			ht_node = ht_node->snext;
		}
		array_index++;
	}
	puts("}\n");
}
