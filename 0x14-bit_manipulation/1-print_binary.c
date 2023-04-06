#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of an unsigned long int
 * @n: unsigned long int to print
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int flag = 0;

	while (mask > 0)
	{
		if ((n & mask) == 0 && flag)
			putchar('0');
		else if ((n & mask) != 0)
		{
			putchar('1');
			flag = 1;
		}
		mask >>= 1;
	}
	if (!flag)
		putchar('0');
}
