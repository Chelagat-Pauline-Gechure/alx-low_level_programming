#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints generated_passs for the crackme5 executable.
 * @argc: The Number of arguments supplied to the Program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char generated_pass[7], *codex;
	int length = strlen(argv[1]), i, Tmp;

	codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	Tmp = (length ^ 59) & 63;
	generated_pass[0] = codex[Tmp];

	Tmp = 0;
	for (i = 0; i < length; i++)
		Tmp += argv[1][i];
	generated_pass[1] = codex[(Tmp ^ 79) & 63];

	Tmp = 1;
	for (i = 0; i < length; i++)
		Tmp *= argv[1][i];
	generated_pass[2] = codex[(Tmp ^ 85) & 63];

	Tmp = 0;
	for (i = 0; i < length; i++)
	{
		if (argv[1][i] > Tmp)
			Tmp = argv[1][i];
	}
	srand(Tmp ^ 14);
	generated_pass[3] = codex[rand() & 63];

	Tmp = 0;
	for (i = 0; i < length; i++)
		Tmp += (argv[1][i] * argv[1][i]);
	generated_pass[4] = codex[(Tmp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		Tmp = rand();
	generated_pass[5] = codex[(Tmp ^ 229) & 63];

	generated_pass[6] = '\0';
	printf("%s", generated_pass);
	return (0);
}
