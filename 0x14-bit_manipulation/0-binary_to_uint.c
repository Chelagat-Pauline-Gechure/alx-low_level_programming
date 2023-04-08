#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary string to an unsigned int
 * @b: pointer to binary string
 *
 * Return: the converted unsigned int, or 0 on error
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (; *b != '\0'; b++)
	{
		if (*b == '0')
		{
			result <<= 1;
		}
		else if (*b == '1')
		{
			result <<= 1;
			result |= 1;
		}
		else
		{
			/* Invalid character, return 0 */
			return (0);
		}
	}

	return (result);
}
