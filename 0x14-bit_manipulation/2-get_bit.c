#include "main.h"
#include <stdio.h>

/**
 * get_bit - gets the value of a bit at a given index
 * @n: unsigned long int to get bit from
 * @index: index of the bit to get, starting from 0
 * Return: value of the bit at index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
int bit_value = 0;
unsigned long int mask;
if (index >= sizeof(unsigned long int) * 8)
return (-1);

mask = 1UL << index;
bit_value = (n & mask) ? 1 : 0;

return (bit_value);
}
