/* Executing a program */
#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 * Return: Always 0.
 */

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	/* First printf function */
	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}

	/* Second printf function*/
	printf("After execve\n");
	return (0);
}
