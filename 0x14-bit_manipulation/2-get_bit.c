#include "main.h"

/**
 * get_bit - this returns value of the bit positioned at an index in a dec no
 * @n: the  number to be found
 * @index: index of said  bit
 *
 * Return: value of said  bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (n >> index) & 1;

	return (bit_value);
}
