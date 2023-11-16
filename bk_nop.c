#include "monty.h"

/**
 *bk_nop - Does absolutely nothing for the bk opcode 'nop'
 *
 *@stack: Pointer to the top mode node of a stack_t linked list
 *@line_number: The current working line number of a bk bytecodes file
 *
 *Return: Void
 */

void bk_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

