#include "main.h"

/**
 * clear_bit - this function will set the value of certain given bit to 0.
 * @n: this is thr  pointer to the number that is to be  changed
 * @index: index of the bitt to be cleared
 *
 * Return: 1 for success, and  -1 in case of a failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
