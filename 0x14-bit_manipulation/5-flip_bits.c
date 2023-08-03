#include "main.h"

/**
 * flip_bits - this function counts the number of bits that is to be changed
 * to get from the first number on to the next
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits to be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int e, count = 0;
	unsigned long int curr;
	unsigned long int exclusive = n ^ m;

	for (e = 63; e >= 0; e--)
	{
		curr = exclusive >> e;
		if (curr & 1)
			count++;
	}

	return (count);
}
