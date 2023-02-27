#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random passwords for 101-crackme
 * Return: zero
 */
int main(void)
{
	int sum;
	char c;

	srand(time(NULL));
	while (sum <= 3756)
	{
		c = rand() % 246;
		sum += c;
		putchar(c);
	}
	putchar(4444 - sum);
	return (0);
}
