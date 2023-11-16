#include "monty.h"

/**
 * err_usage - Prints usage error messages
 *
 * Return: EXIT_FAILURE
 */

int err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
