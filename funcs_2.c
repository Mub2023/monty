#include "monty.h"
/**
 * M_add - Add the top two values of stack_t in linked list.
 * @stack: a pointer to the top node pf stack_t in linked list.
 * @line_number: The current working line number of the file.
 */
void M_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(small_stack(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * M_sub  - subtracts the second value from the yop of list
 * @stack: a pointer to the top node pf stack_t in linked list.
 * @line_number: The current working line number of the file.
 */
void M_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(small_stack(line_number, "sub"));
				return;
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * M_div - Divides the scond value from list by the top value.
 * @stack: a pointer to the top node pf stack_t in linked list.
 * @line_number: The current working line number of the file.
 */
void M_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(small_stack(line_number, "div"));
		return;
	}
	if ((*stack)->next->next->n == 0)
	{
		set_op_tok_error(div_by_zero(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * M_mul - multiplies the second value from the list by the top value.
 * @stack: a pointer to the top node pf stack_t in linked list.
 * @line_number: The current working line number of the file.
 */
void M_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(small_stack(line_number, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * M_mod - modulus if the second value from the top value in linkef list.
 * @stack: a pointer to the top node pf stack_t in linked list.
 * @line_number: The current working line number of the file.
 */
void M_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(small_stack(line_number, "mod"));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}
