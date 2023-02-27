#include "main.h"

/**
 * _strlen - Function that returns the length of a string
 *
 * @s: the string
 *
 * Return: String length
 */
int _strlen(char *s)
{
	int string_len;

	for (string_len = 0; s[string_len] != '\0' ; string_len++)
		;
	return (string_len);
}
