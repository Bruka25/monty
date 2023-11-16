#include "monty.h"

/**
 *err_pchar - Prints pchar error messages for empty stacks
 *              empty stacks and non-character values
 *
 *@line_number: Line number in Monty bytecodes file where error occurred
 *@message: The corresponding error message to print
 *
 * Return: EXIT_FAILURE
 */
int err_pchar(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

