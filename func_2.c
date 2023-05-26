#include "monty.h"
/**
 * free_stack - A function that frees the memory allocated for stack.
 * @stack: Pointer to the doubly linked list representation of a stack.
 * Return: Nothing.
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
