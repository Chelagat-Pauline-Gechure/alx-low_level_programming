#include "main.h"
/**
 * puts_half - function that prints half of a string,
 *followed by a new line.
 *
 * @str: This is the input string
 */
void puts_half(char *str)
{
	int full_index, half;

	full_index = 0;
	while (str[full_index] != '\0')
		full_index++;

	half = full_index / 2;

	if (full_index % 2 == 1)
		half++;

	while (half < full_index)
	{
		_putchar(str[half]);
		half++;
	}
	_putchar('\n');
}
