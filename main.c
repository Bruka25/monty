#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 *main - Entry point for the program
 *
 *@argc: Count of arguments passed to the program
 *@argv: Pointer to pointer to the arguments
 *
 *Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (err_usage());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (cant_open_err(argv[1]));
	exit_code = run_bk(script_fd);
	fclose(script_fd);
	return (exit_code);
}
