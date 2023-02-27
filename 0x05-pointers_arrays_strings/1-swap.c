#include "main.h"

/**
 * swap_int - function that swaps the values of two integers.
 * @a: this is the first integer
 * @b: this is the second integer
 *
 *
 */
void swap_int(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
