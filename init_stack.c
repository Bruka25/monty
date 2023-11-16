#include "monty.h"

/**
 *initialize_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes
 *
 *@stack: Pointer to an unitialized stack_t stack
 *
 *Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int initialize_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (memory_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}
