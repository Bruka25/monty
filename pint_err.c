#include "monty.h"
/**
 *pint_err -  Outputs Pint error messages for empty stacks
 *
 *@line_number: Line number in Monty bytecodes file where error occurred
 *
 * Return: EXIT_FAILURE
 */
int pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
