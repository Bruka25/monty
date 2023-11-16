#include "monty.h"

/**
 * get_buff_length - Gets length of buffer needed for an unsigned int
 *
 *@num: Number to get length
 *@base: Base of number representation used by buffer
 *
 *Return: integer containing length of buffer
 */
int get_buff_length(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
