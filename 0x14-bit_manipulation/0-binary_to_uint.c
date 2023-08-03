#include "main.h"

/**
 * binary_to_uint - It  converts a given  binary number into an unsigned int
 * @b: this string contains the bin number
 *
 * Return: the converted binary number is returne .
 */
unsigned int binary_to_uint(const char *b)
{
	int z;
	unsigned int deci_val = 0;

	if (!b)
		return (0);

	for (z = 0; b[z]; z++)
	{
		if (b[z] < '0' || b[z] > '1')
			return (0);
		deci_val = 2 * deci_val + (b[z] - '0');
	}

	return (deci_val);
}
