#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <string.h>


int run_bk(FILE *script_fd);

/**
 *tok_free - Frees the global op_toks array of strings
 *
 *Return: Void
 */

void tok_free(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 *length_token - Gets the length of current op_toks
 *
 *Return: Length of current op_toks
 */

unsigned int length_token(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 *check_delim - Checks if a line read from getline only contains delimiters
 *
 *@line: Pointer to the line
 *@delims: String of delimiter characters
 *
 *Return: 1 if they contain only delim or 0
 */

int check_delim(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 *opocode_getter - Matches an opcode with its corresponding function
 *
 *@opcode: Opcode to match
 *
 *Return: Pointer to the corresponding function
 */

void (*opocode_getter(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", bk_push},
		{"pall", bk_pall},
		{"pint", bk_pint},
		{"pop", bk_pop},
		{"swap", bk_swap},
		{"add", bk_add},
		{"nop", bk_nop},
		{"sub", bk_sub},
		{"div", bk_div},
		{"mul", bk_mul},
		{"mod", bk_mod},
		{"pchar", bk_pchar},
		{"pstr", bk_pstr},
		{"rotl", bk_rotl},
		{"rotr", bk_rotr},
		{"stack", bk_stack},
		{"queue", bk_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 *run_bk - Primary function to execute bytecodes script
 *
 *@script_fd: File descriptor for an open bk bytecodes script
 *
 *Return: EXIT_SUCCESS on success or err on failure
 */
int run_bk(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (initialize_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (check_delim(line, DELIMS))
				continue;
			stack_free(&stack);
			return (memory_error());
		}
		else if (op_toks[0][0] == '#')
		{
			tok_free();
			continue;
		}
		op_func = opocode_getter(op_toks[0]);
		if (op_func == NULL)
		{
			stack_free(&stack);
			exit_status = instruct_err(op_toks[0], line_number);
			tok_free();
			break;
		}
		prev_tok_len = length_token();
		op_func(&stack, line_number);
		if (length_token() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			tok_free();
			break;
		}
		tok_free();
	}
	stack_free(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (memory_error());
	}

	free(line);
	return (exit_status);
}
