#include "monty.h"
/**
 * free_stack - free stack from stack_t.
 * @stack: A pointer to the top (stack) or the bottom.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
/**
 * init_stack - Initializes a stack_t stack with beginning of the stack.
 * or the end of queue nodes.
 * @stack: a pointer to an unitialized stack_t stack.
 * Return: error occurs - EXIT_FAILURE, or otherwise EIXT_SUCCES.
 */
int init_stack(stack_t **stack)
{
	stack_t *x;

	x = malloc(sizeof(stack_t));
	if (x == NULL)
		return (malloc_failed());
	x->n = STACK;
	x->prev = NULL;
	x->next = NULL;

	*stack = x;

	return (EXIT_SUCCESS);
}
/**
 * mode_check - checks if the stack_t is in stack or queue mode.
 * @stack: a pointer to the top (stack) or bottom (queue).
 * Return: 1 if the stack_t is in QUEUE mode.
 *         0 if the stack_t is in STACK mode.
 *         2 otherwise.
 */
int mode_check(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
