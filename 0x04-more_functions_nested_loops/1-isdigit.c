#include "main.h"

/**
 *_isdigit - check for a digit 0 through 9
 *@c: The digit charcater to be checked
 * Return:1 if digit and 0 otherwise
 */

int _isdigit(int c)
{
if (c >= 48 && c <= 57)
{
return (1);
}
return (0);
}
