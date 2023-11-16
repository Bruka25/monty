#include "monty.h"

/**
 *bk_div - Divides the second value from the top of
 *             a stack_t linked list by the top value
 *
 *@stack: Pointer to the top mode node of a stack_t linked list
 *@line_number: The current working line number of a bk bytecodes file
 *
 *Return: Void
 */
void bk_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		token_errors_set(empty_stack_err(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		token_errors_set(err_div(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	bk_pop(stack, line_number);
}
