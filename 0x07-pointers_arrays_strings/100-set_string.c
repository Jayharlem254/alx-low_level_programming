#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: Pointer to the pointer to a char to be set.
 * @to: Pointer to the char to set the pointer to.
 *
 * Description: The function takes a pointer to a pointer to a char and sets
 * the value of the pointer to the char pointed by the second parameter.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
