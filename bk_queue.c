#include "monty.h"

/**
 *bk_queue - Converts a stack to a queue
 *
 *@stack: A pointer to the top mode node of a stack_t linked list
 *@line_number: The current working line number of a bk bytecodes file
 *
 *Return: Void
 */
void bk_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

