#include "main.h"
/**
*_strcat - function that concatenates two strings.
*@dest: pointer to destination string.
*@src: pointer to source string.
*
*Return: pointer to destination string.
 */
char *_strcat(char *dest, char *src)
{
int string_length, j;

string_length = 0;
while (dest[string_length] != '\0')
{
string_length++;
}
for (j = 0; src[j] != '\0'; j++, string_length++)
{
dest[string_length] = src[j];
}
dest[string_length] = '\0';
return (dest);
}
