#include "monty.h"

/**
 *bk_pchar - Prints the character in the top value
 *               node of a stack_t linked list
 *
 *@stack: Pointer to the top mode node of a stack_t linked list
 *@line_number: Current working line number of a bk bytecodes file
 *
 *Return: Void
 */
void bk_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		token_errors_set(err_pchar(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		token_errors_set(err_pchar(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
