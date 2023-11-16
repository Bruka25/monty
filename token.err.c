#include "monty.h"

/**
 *token_errors_set - Sets last element of op_toks to be an error code
 *
 *@error_code: Integer to store as a string in op_toks
 *
 *Return: Void
 */

void token_errors_set(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = length_token();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		memory_error();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = int_getter(error_code);
	if (!exit_str)
	{
		free(new_toks);
		memory_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
