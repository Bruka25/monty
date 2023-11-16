#include "monty.h"

/**
 *argument_err - Prints invalid monty_push argument error messages
 *
 *@line_number: Line number in Monty bytecodes file where error occurred
 *
 *Return: EXIT_FAILURE
 */
int argument_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
