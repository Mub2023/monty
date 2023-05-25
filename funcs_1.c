#include "monty.h"
/**
 * push - pashes a value to stack_t linked list.
 * @stack: A pointer to the top mode node of stack_t.
 * @line_number: the current working line integer.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new;
	int x;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_failed());
		return;
	}
	if (Gvar[1] == NULL)
	{
		set_op_tok_error(no_integer(line_number));
		return;
	} for (x = 0; Gvar[1][x]; x++)
	{
		if (Gvar[1][x] == '-' && x == 0)
			continue;
		if (Gvar[1][x] < '0' || Gvar[1][x] > '9')
		{
			set_op_tok_error(no_integer(line_number));
			return;
		}
	} new->n = atoi(Gvar[1]);
	if (mode_check(*stack) == STACK)
	{
		temp = (*stack)->next;
		new->prev = *stack;
		new->next = temp;
		if (temp)
			temp->prev = new;
		(*stack)->next = new;
	} else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new->prev = temp;
		new->next = NULL;
		temp->next = new;
	}
}
/**
 * pall - prints the value of the stack_t in linked list.
 * @stack: A pointer to the top mode node of stack_t.
 * @line_number: the current working line integer.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}
/**
 * pint - prints the top value of stack_T linked list.
 * @stack: A pointer to the top mode node of stack_t.
 * @line_number: the current working line integer.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(empty_stack(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}



/**
 * pop - prints the top value of stack_T linked list.
 * @stack: A pointer to the top mode node of stack_t.
 * @line_number: the current working line integer.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_empty(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
/**
 * swap - sawps the top two values elemnts of a stack_t linked list.
 * @stack: A pointer to the top mode node of stack_t.
 * @line_number: the current working line integer
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(small_stack(line_number, "swap"));
		return;
	}
	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
