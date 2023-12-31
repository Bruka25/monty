#include "monty.h"

/**
 *err_div - Prints division error messages for division by 0 *
 *@line_number: Line number in Monty bytecodes file where error occurred
 *
 *Return: EXIT_FAILURE
 */
int err_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
