#include "monty.h"

/**
 *bk_stack - Converts a queue to a stack
 *
 *@stack: Pointer to the top mode node of a stack_t linked list
 *@line_number: Current working line number of a bk bytecodes file
 *
 *Return: Void
 */
void bk_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
