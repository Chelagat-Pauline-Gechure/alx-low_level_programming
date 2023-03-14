#include <stdio.h>

/**
 * main -using sizeof to dynamically determine the sixe of types char, int and float
 *
 * Retun: ALways 0
 */
int main (void)
{
	int n;

	printf("Size of type 'char' on my computer: %lu bytes\n", sizeof(char));
	printf("Size of type 'int' on my computer: %lu bytes\n", sizeof(int));
	printf("Size of tye 'float' on my computer: %lu bytes\n", sizeof(float));
	printf("Size of type of my variable n on my computer: %lu bytes\n", sizeof(n));
	return (0);
}	
