#include "main.h"

/**
 * set_bit - this function sets a bit at a specified index to 1.
 * @n: this is he  pointer to the number to be changed
 * @index: index of the bit to set to 1
 *
 * Return: 1 for a  success,and  -1 for its  failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
