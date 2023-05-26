#include "monty.h"
/**
 * execute - Function that checks for a command "opcode" and execute the
 * function if there's a match.
 * @token: Tokane containing the opcode to execute.
 * @stack: Doubly linked list representation of a stack.
 * @line_num: Line number where the opcode was found.
 * Return: EXIT_SUCCESS in success, or EXIT_FAILURE on failure.
 */
int execute(char **token, stack_t **stack, unsigned int line_num)
{
	unsigned int x = 0;

	instruction_t op[] = {
		{"pall", M_pall},
		{"pint", M_pint},
		{"pop", M_pop},
		{"swap", M_swap},
		{"add", M_add},
		{"sub", M_sub},
		{"mul", M_mul},
		{"div", M_div},
		{"mod", M_mod},
		{"pchar", M_pchar},
		{"pstr", M_pstr},
		{"rotl", M_rotl},
		{"rotr", M_rotr},
		{"null", NULL}
	};

	for (x = 0; x < 14; x++)
	{
		if (strcmp(op[x].opcode, token[0]) == 0)
		{
			op[x].f(stack, line_num);
			return (EXIT_SUCCESS);
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", line_num, token[0]);
	return (EXIT_FAILURE);
}
/**
  * M_push - A function that pushes an element to stack.
  * @stack: The pointer to the stck struct.
  * @token: The pointer to command.
  * @line_num: The number of the line.
  * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
  */
int M_push(stack_t **stack, char **token, unsigned int line_num)
{
	stack_t *new;
	int x = 0;

	if (token[1] == NULL)
		return (f_errors(0, line_num));
	while (token[1][x])
	{
		if (token[1][x] == '-' && x == 0)
		{
			x++;
			continue;
		}
		if (token[1][x] < '0' || token[1][x] > '9')
		{
			free_stack(stack);
			return (f_errors(0, line_num));
		}
		x++;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (usage_error(0));

	new->n = atoi(token[1]);
	if ((*stack) != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
	return (EXIT_SUCCESS);
}

/**
 * M_pushq - A function that pushes an element to queue.
 * @stack: The pointer to the stck struct.
 * @token: The pointer to command.
 * @line_num: The number of the line.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int M_pushq(stack_t **stack, char **token, unsigned int line_num)
{
	stack_t *new, *tmp = NULL;
	int x = 0;

	if (token[1] == NULL)
		return (f_errors(0, line_num));
	while (token[1][x])
	{
		if (token[1][x] == '-' && x == 0)
		{
			x++;
			continue;
		}
		if (token[1][x] < '0' || token[1][x] > '9')
		{
			free_stack(stack);
			return (f_errors(0, line_num));
		}
		x++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (usage_error(0));
	new->next = NULL;
	new->prev = NULL;
	new->n = atoi(token[1]);
	if (!stack || !(*stack))
	{
		(*stack) = new;
		return (EXIT_SUCCESS);
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
/**
 * M_pall - A function that prints the values of the stack_t.
 * @stack: The pointer to the top of a stack_t.
 * @line_num: The number of the line.
 * Return: Nothing.
 */
void M_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;
	(void)line_num;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
