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
