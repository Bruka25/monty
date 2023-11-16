#include "monty.h"

/**
 *bk_rotl - Rotates the top value of a stack_t linked list to the bottom
 *
 *@stack: Pointer to the top mode node of a stack_t linked list
 *@line_number: Current working line number of a bk bytecodes file
 *
 *Return: Void
 */
void bk_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}
