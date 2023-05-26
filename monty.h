#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

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

int main(int ac, char **av);
void free_stack(stack_t **stack);
int M_run(FILE *fd);
char **tokening(char *line, char *delim);
int empty_line(char *line, char *delims);
int execute(char **token, stack_t **stack, unsigned int line_num);
int M_push(stack_t **stack, char **token, unsigned int line_num);
int M_pushq(stack_t **stack, char **token, unsigned int line_num);
void M_pall(stack_t **stack, unsigned int line_num);
void M_pint(stack_t **stack, unsigned int line_num);
void M_pop(stack_t **stack, unsigned int line_num);
void M_swap(stack_t **stack, unsigned int line_num);
void M_sub(stack_t **stack, unsigned int line_num);
void M_add(stack_t **stack, unsigned int line_num);
void M_mul(stack_t **stack, unsigned int line_number);
void M_div(stack_t **stack, unsigned int line_number);
void M_mod(stack_t **stack, unsigned int line_number);
void M_pchar(stack_t **stack, unsigned int line_number);
void M_pstr(stack_t **stack, unsigned int line_number);


void M_rotl(stack_t **stack, unsigned int line_number);
void M_rotr(stack_t **stack, unsigned int line_number);


int usage_error(int flag);
int open_error(char *filename);
int f_errors(int flag, unsigned int line_num);

#endif /* thanks bye */
