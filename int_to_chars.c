#include"monty.h"
/**
 * M_rotl - A function that rotates the stack to the top.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void M_rotl(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *c = *stack;
	(void)line_number;

	if (*stack)
	{
		temp = c->n;
		while (c->next != NULL)
		{
			c->n = c->next->n;
			c = c->next;
		}
		c->n = temp;
	}
}
/**
 * M_rotr - A function that rotates the stack to the bottom.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void M_rotr(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *c = *stack;
	(void)line_number;

	if (*stack)
	{
		while (c->next != NULL)
			c = c->next;
		temp = c->n;
		while (c->prev != NULL)
		{
			c->n = c->prev->n;
			c = c->prev;
		}
		c->n = temp;
	}
}
