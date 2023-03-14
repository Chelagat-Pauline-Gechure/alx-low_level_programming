#include <stdio.h>

/**
 * main - printing the address of a pointer
 *
 * Return: ALways 0
 */
int main (void)
{
	int n;
	int *p;

	n = 98;
	p = &n;

	printf("Address of a variable 'p': %p\n", &p);
	return (0);
}
