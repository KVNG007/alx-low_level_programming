#include "main.h"

/**
 * print_binary - it prints the binary equivalent of a given number in decimal
 * @n: this is the number to be  printed in binary
 */
void print_binary(unsigned long int n)
{
	int l, cnt = 0;
	unsigned long int current;

	for (l = 63; l >= 0; l--)
	{
		current = n >> l;

		if (current & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0');
	}
	if (!cnt)
		_putchar('0');
}
