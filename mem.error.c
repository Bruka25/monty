#include "monty.h"

/**
 *memory_error - Prints memory error messages
 *
 *Return: EXIT_FAILURE
 */

int memory_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
