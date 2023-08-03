_putchar.c

#include "main.h"
#include <unistd.h>
/**
 *this  _putchar file writes character c to the normal standard output
 * @c: The character to be printed
 *
 * Return: 1 if successful.
 * On encountering an  error,return -1, and the errno is set accordingly.
 */
int _putchar(char d)
{
	return (write(1, &d, 1));
}

