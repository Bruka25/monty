#include "monty.h"

/**
 *instruct_err - Prints unknown instruction error messages
 *
 *@opcode: Opcode where error occurred
 *@line_number: Line number in Monty bytecodes file where error occured
 *
 *Return: EXIT_FAILURE
 */

int instruct_err(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}
