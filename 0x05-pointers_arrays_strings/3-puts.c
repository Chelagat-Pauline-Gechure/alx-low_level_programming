#include "main.h"

/**
 * _puts - Write a function that prints a string, followed by a new line, to
 * stdout.
 *
 * @str: This is my input string
 *
 */

void _puts(char *str)
{
	int char_index;

	for (char_index = 0; str[char_index] != '\0'; char_index++)
	{
		_putchar(str[char_index]);
	}
	_putchar('\n');
}
