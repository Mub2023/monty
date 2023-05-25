#include "monty.h"
/**
 * pop_empty - prints pop error massage on stderr.
 * @line_number: line number in script where error ouccred.
 * Return: (EXIT_FAILURE) always.
 */
int pop_empty(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * empty_stack - prints an stack empty error on stderr.
 * @line_number:line number in script where error ouccred.
 * Return: (EXIT_FAILURE) always.
 */
int empty_stack(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * small_stack - prints an small stack error on stderr.
 * @line_number:line number in script where error ouccred.
 * @op: operation where error occured.
 * Return: (EXIT_FAILURE) always.
 */
int small_stack(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}
/**
 * div_by_zero - prints an division by zero error on stderr.
 * @line_number:line number in script where error ouccred.
 * Return: (EXIT_FAILURE) always.
 */
int div_by_zero(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * pchar_empty - print empty stacks or non`char values.
 * @line_number:line number in script where error ouccred.
 * @msg: te corresponding error nassage to print.
 * Return: (EXIT_FAILURE) always.
 */
int pchar_empty(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	return (EXIT_FAILURE);
}
