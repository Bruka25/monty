#include "monty.h"

/**
 *check_data - Checks if a stack_t linked list is in stack or queue mode
 *
 *@stack: Pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 *Return: If the stack_t is in stack mode - STACK (0)
 *        If the stack_t is in queue mode - QUEUE (1)
 *        Otherwise - 2
 */

int check_data(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
