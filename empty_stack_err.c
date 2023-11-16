#include "monty.h"

/**
 * empty_stack_err - Outputs monty math function error messages
 *                     for stacks/queues smaller than two nodes
 *
 *@line_number: Line number in Monty bytecodes file where error occurred
 *@op: Operation where the error occurred
 *
 * Return: EXIT_FAILURE
 */
int empty_stack_err(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}
