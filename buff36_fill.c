#include "monty.h"

/**
 *buff36_filler - fills buffer with correct numbers up to base 36
 *
 *@num: number to be converted to string of given base
 *@base: base of number used in conversion
 *@buff: buffer to fill with result of conversion
 *@buff_size: size of buffer in bytes
 *
 *Return: Void
 */
void buff36_filler(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

