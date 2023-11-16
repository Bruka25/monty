#include "monty.h"

/**
 *bk_rotr - Rotates the bottom value of a stack_t linked list to the top
 *
 *@stack: Pointer to the top mode node of a stack_t linked list
 *@line_number: Current working line number of a bk bytecodes file
 *
 *Return: Void
 */
void bk_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}
