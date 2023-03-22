#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"


/**
 *print_name - prints a name
 * @name: name to be printed
 * @f: pointer to function
 * Return: name
 */

void print_name(char *name, void (*f)(char *))
{
	if (f == NULL || name == NULL)
		return;
	f(name);
}
