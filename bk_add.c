#include "monty.h"

/**
 *bk_add - Adds the top two values of a stack_t linked list
 *
 *@stack: Pointer to the top mode node of a stack_t linked list
 *@line_number: Current working line number of a bk bytecodes file
 *
 *Return: Void
 */
void bk_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		token_errors_set(empty_stack_err(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	bk_pop(stack, line_number);
}
