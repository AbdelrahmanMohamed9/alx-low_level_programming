#include <unistd.h>
#include "main.h"

/**
 * _putchar - write char c to a Stdout
 * @c: char to print
 *
 * Return: 1 if success and -1 if not success or in error
 */

int _putchar(char x)
{
	return (write(1, &c, 1));
}
