#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if there is one or more characters
 *         in the string 'b' that is not 0 or 1, or if 'b' is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	if (b == NULL) /* Check if 'b' is NULL */
		return 0;

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0') /* Skip '0' characters */
			continue;
		else if (b[i] == '1') /* Add corresponding power of 2 for '1' characters */
			result |= (1 << ((sizeof(unsigned int) * 8) - 1 - i));
		else /* Return 0 for any other character that is not '0' or '1' */
			return 0;
	}

	return result;
}

