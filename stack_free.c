#include "monty.h"

/**
 *stack_free - Frees a stack_t stack
 *
 *@stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t
 *
 *Return: Void
 */
void stack_free(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
