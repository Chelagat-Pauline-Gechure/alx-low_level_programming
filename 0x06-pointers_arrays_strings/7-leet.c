#include "main.h"
/**
 *leet - encodes a string into 1337.
 *letters a and A are replaced by 4.
 *Letters e and E are replaced by 3
 *Letters o and O are replaced by 0
 *Letters t and T are replaced by 7
 *Letters l and L are replaced by 1
 *@s: pointer to string.
 *
 *Return: pointer to s.
 */
char *leet(char *s)

{
int countstring, alpCount;

char leetalp[] = "aAeEoOtTlL";
char leetnum[] = "4433007711";

/*  scan through string */
countstring = 0;
while (s[countstring] != '\0')

/* check whether leetalp is found */
{
alpCount = 0;
while (alpCount < 10)
{
if (leetalp[alpCount] == s[countstring])
{
s[countstring] = leetnum[alpCount];
}
alpCount++;
}
countstring++;
}
return (s);
}
