#include "monty.h"

/**
 *cant_open_err - Prints file opening error messages with file name
 *
 *@filename: Name of file failed to open
 *
 *Return: EXIT_FAILURE
 */

int cant_open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
