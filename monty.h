#ifndef monty_h
#define monty_h

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdarg.h>
#include <assert.h>
#include <errno.h>
#include <limits.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **Gvar;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int use_errors(void);
int open_error(char *Fname);
int unknown_op(char *opcode, unsigned int line_number);
int no_integer(unsigned int line_number);
int malloc_failed(void);
int pop_empty(unsigned int line_number);
int empty_stack(unsigned int line_number);
int small_stack(unsigned int line_number, char *op);
int div_by_zero(unsigned int line_number);
int pchar_empty(unsigned int line_number, char *msg);
char *Gint(int num);
unsigned int _abs(int x);
int get_num_len(unsigned int num, unsigned int base);
void fill_num_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void M_add(stack_t **stack, unsigned int line_number);
void M_sub(stack_t **stack, unsigned int line_number);
void M_div(stack_t **stack, unsigned int line_number);
void M_mul(stack_t **stack, unsigned int line_number);
void M_mod(stack_t **stack, unsigned int line_number);
void M_nop(stack_t **stack, unsigned int line_number);
void M_pchar(stack_t **stack, unsigned int line_number);
void M_pstr(stack_t **stack, unsigned int line_number);
void M_rotl(stack_t **stack, unsigned int line_number);
void M_rotr(stack_t **stack, unsigned int line_number);
void M_stack(stack_t **stack, unsigned int line_number);
void M_queue(stack_t **stack, unsigned int line_number);
void free_tok(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
void free_tok(void);
unsigned int token_arr_len(void);
int R_monty(FILE *OFile);
char **strtow(char *str, char *delims);
int is_delims(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
void set_op_tok_error(int error_code);
int mode_check(stack_t *stack);
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);


#endif /* thanks bye*/
