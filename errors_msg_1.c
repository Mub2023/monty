#include "monty.h"
int use_errors(void);
int malloc_failed(void);
int open_error(char *Fname);
int no_integer(unsigned int line_number);
int no_integer(unsigned int line_number);
/**
 * use_errors - Prints use error on stderr.
 * Return: Always EXIT_FAILURE always.
 */
int use_errors(void)
{
	fprintf(stderr, "Error: Can't open file\n");
	return (EXIT_FAILURE);
}
/**
 * malloc_failed - print malloc error on stderr.
 * Return: Always EXIT_FAILURE always.
 */
int malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * open_error - prints file opening error on stderr.
 * @Fname: name of file failed to open.
 * Return: Always EXIT_FAILURE always.
 */
int open_error(char *Fname)
{
	fprintf(stderr, "Error: Can't open file %s\n", Fname);
	return (EXIT_FAILURE);
}
/**
 * unknown_op - prints unkown instruction on stderr.
 * @opcode: where is the op error occured.
 * @line_number: Line number in monty bytecodes files where occred.
 * Return: Always EXIT_FAILURE always.
 */
int unknown_op(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}
/**
 * no_integer - prints invailed monty_pus arg on stderr.
 * @line_number:Line number in monty bytecodes files where occred.
 * Return: Always EXIT_FAILURE always.
 */
int no_integer(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
