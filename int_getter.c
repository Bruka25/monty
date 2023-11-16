#include "monty.h"

/**
 *int_getter - gets a character pointer to new string containing int
 *
 *@num: Number to be converted to string
 *
 *Return: character pointer to newly created string or NULL
 */
char *int_getter(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _absolute(num);
	length = get_buff_length(temp, 10);

	if (num < 0 || num_l < 0)
		length++;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	buff36_filler(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}
