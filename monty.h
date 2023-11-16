#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void stack_free(stack_t **stack);
int initialize_stack(stack_t **stack);
int check_data(stack_t *stack);
void free_tokens(void);
unsigned int length_token(void);
int run_bk(FILE *script_fd);
void token_errors_set(int error_code);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/*mandatory monty opocde funcs*/
void bk_push(stack_t **stack, unsigned int line_number);
void bk_pall(stack_t **stack, unsigned int line_number);
void bk_pint(stack_t **stack, unsigned int line_number);
void bk_pop(stack_t **stack, unsigned int line_number);
void bk_swap(stack_t **stack, unsigned int line_number);
void bk_add(stack_t **stack, unsigned int line_number);
void bk_nop(stack_t **stack, unsigned int line_number);

/* advanced monty opocode funcs*/
void bk_sub(stack_t **stack, unsigned int line_number);
void bk_div(stack_t **stack, unsigned int line_number);
void bk_mul(stack_t **stack, unsigned int line_number);
void bk_mod(stack_t **stack, unsigned int line_number);
void bk_pchar(stack_t **stack, unsigned int line_number);
void bk_pstr(stack_t **stack, unsigned int line_number);
void bk_rotl(stack_t **stack, unsigned int line_number);
void bk_rotr(stack_t **stack, unsigned int line_number);
void bk_stack(stack_t **stack, unsigned int line_number);
void bk_queue(stack_t **stack, unsigned int line_number);

char **strtow(char *str, char *delims);
char *int_getter(int n);


int err_usage(void);
int memory_error(void);
int cant_open_err(char *filename);
int instruct_err(char *opcode, unsigned int line_number);
int argument_err(unsigned int line_number);

int  empty_stack_err(unsigned int line_number, char *op);
int err_div(unsigned int line_number);
int err_pop_empty(unsigned int line_number);
int err_div(unsigned int line_number);
int err_pchar(unsigned int line_number, char *message);

char *int_getter(int num);
unsigned int _absolute(int);
int get_buff_length(unsigned int num, unsigned int base);
void buff36_filler(unsigned int num, unsigned int base,
		       char *buff, int buff_size);


void tok_free(void);
unsigned int length_token(void);
int check_delim(char *line, char *delims);
void (*opocode_getter(char *opcode))(stack_t**, unsigned int);
int run_bk(FILE *script_fd);


void stack_free(stack_t **stack);
int initialize_stack(stack_t **stack);
int check_data(stack_t *stack);


/*string functions*/
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);

/*tokenize functions*/
char **strtow(char *str, char *delims);
int is_delimiter(char ch, char *delims);
int word_len(char *str, char *delims);
int word_count(char *str, char *delims);
char *next_word(char *str, char *delims);

/*error funcs*/
int err_usage(void);
int memory_error(void);
int cant_open_err(char *filename);
int instruct_err(char *opcode, unsigned int line_number);
int argument_err(unsigned int line_number);
int err_pop_empty(unsigned int line_number);
int pint_err(unsigned int line_number);
int empty_stack_error(unsigned int line_number, char *op);
int err_div(unsigned int line_number);
int err_pchar(unsigned int line_number, char *message);

#endif /* MONTY_H */
