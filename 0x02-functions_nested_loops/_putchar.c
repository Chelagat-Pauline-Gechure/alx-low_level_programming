#include "main.h"
#include <unistd.h>
/**
 * writess the character to c to stdout
 */
int _putchar (char c)
{
	return (write(1,&c, 1));
}
