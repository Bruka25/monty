#include "monty.h"

/**
 *bk_sub - Subtracts the second value from the top of
 *            a stack_t linked list by the top value
 *
 *@stack: A pointer to the top mode node of a stack_t linked list
 *@line_number: The current working line number of a bk bytecodes file
 *
 *Return: Void
 */
void bk_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		token_errors_set(empty_stack_err(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	bk_pop(stack, line_number);
}
