#include "main.h"

/**
 * get_endianness - this function checks if a machine is little or big endian.
 * Return: 0 if  big,ans  1 if little
 */
int get_endianness(void)
{
	unsigned int j = 1;
	char *d = (char *) &j;

	return (*d);
}
