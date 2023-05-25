#include "monty.h"
/**
 * free_tok - frees the global Gvar array of string.
 */
void free_tok(void)
{
	size_t x = 0;

	if (Gvar == NULL)
		return;

	for (x = 0; Gvar[x]; x++)
		free(Gvar[x]);
	free(Gvar);
}
/**
 * token_arr_len - gets the length of current op_toa.
 * Return: he length of current op_toa.
 */
unsigned int token_arr_len(void)
{
	unsigned int len = 0;

	while (Gvar[len])
		len++;
	return (len);
}
/**
 * is_empty_line - checks if the line read from getline only
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 * Return: if the line only contains delimiters - 1.
 * otherwise 0.
 */
int is_empty_line(char *line, char *delims)
{
	int x, y;

	for (x = 0; line[x]; x++)
	{
		for (y = 0; delims[y]; y++)
		{
			if (line[x] == delims[y])
				break;
		}
		if (delims[y] == '\0')
			return (0);
	}
	return (1);
}
/**
 * get_op_func - matches an opcode with it corresponding function.
 * @opcode: the opcode to match.
 * Return: A pointer to tje corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", M_add},
		{"nop", M_nop},
		{"sub", M_sub},
		{"div", M_div},
		{"mul", M_mul},
		{"mod", M_mod},
		{"pchar", M_pchar},
		{"pstr", M_pstr},
		{"rotl", M_rotl},
		{"rotr", M_rotr},
		{"stack", M_stack},
		{"queue", M_queue},
		{NULL, NULL},
	};
	int x;

	for (x = 0; op_funcs[x].opcode; x++)
	{
		if (strcmp(opcode, op_funcs[x].opcode) == 0)
			return (op_funcs[x].f);
	}
	return (NULL);
}
/**
 * R_monty - important func to execte monty btecodes  scripts.
 * @OFile: file descriptor for open monty bytecodes scripts.
 * Return: EXIT_SUCCESS on success or error code.
 */
int R_monty(FILE *OFile)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_stat = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &len, OFile) != -1)
	{ line_number++;
		Gvar = strtow(line, DELIMS);
		if (Gvar == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_failed());
		} else if (Gvar[0][0] == '#')
		{ free_tok();
			continue;
		} op_func = get_op_func(Gvar[0]);
		if (op_func == NULL)
		{ free_stack(&stack);
			exit_stat = unknown_op(Gvar[0], line_number);
			free_tok();
			break;
		} prev_tok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len)
		{
			if (Gvar && Gvar[prev_tok_len])
				exit_stat = atoi(Gvar[prev_tok_len]);
			else
				exit_stat = EXIT_FAILURE;
			free_tok();
			break;
		} free_tok();
	} free_stack(&stack);
	if (line && *line == 0)
	{ free(line);
		return (malloc_failed());
	} free(line);
	return (exit_stat);
}
