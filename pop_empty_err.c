#include "monty.h"

/**
 *err_pop_empty - Prints pop error messages for empty stacks
 *
 *@line_number: Line number in script where error occured
 *
 *Return: EXIT_FAILURE
 */

int err_pop_empty(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
