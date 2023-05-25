#include "monty.h"
/**
 * M_rotl - Rotates the top value of linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number on the working file.
 */
void M_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *last;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	last = (*stack)->next;
	while (last->next != NULL)
		last = last->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	top->next = NULL;
	top->prev = last;

	(void)line_number;
}
/**
 * M_rotr - Rotates the bottom value of the stacks list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number on the working file.
 */
void M_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *last;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	last = (*stack)->next;
	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	(*stack)->next = last;
	last->prev = *stack;
	last->next = top;
	top->prev = last;

	(void)line_number;
}
/**
 * M_stack - converts quque to stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number on the working file.
 */
void M_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
/**
 * M_queue - converts a stack to queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number on the working file.
 */
void M_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
