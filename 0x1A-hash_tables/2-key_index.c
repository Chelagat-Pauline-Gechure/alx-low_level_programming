#include "hash_tables.h"

/**
 * key_index - calculates the hash value of the key
 * and gives the index of a key in the hash table
 * @key: the key
 * @size: size of the array of the hash table
 *
 * Return: the index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	hash_value = hash_djb2(key);
	return (hash_value % size);
}
