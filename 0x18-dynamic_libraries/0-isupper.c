#include "main.h"

/**
 *_isupper - check for uppercase characters
 *@c: The uppercase charcater to be checked
 * Return:1 if uppercase and 0 otherwise
 */

int _isupper(int c)
{
if (c >= 65 && c <= 90)
{
return (1);
}
return (0);
}
