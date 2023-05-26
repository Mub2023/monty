#include "monty.h"
/**
 * M_run - A function that runs a Monty bytecodes script.
 * @fd: File descriptor for an open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
int M_run(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL, delim[] = " \n\t\a\b";
	size_t len = 0, mode = 1;
	unsigned int line_num = 0, exit_status = EXIT_SUCCESS;

	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		if (empty_line(line, delim))
			continue;
		token = tokening(line, delim);
		if (token[0][0] == '#' || strcmp(token[0], "nop") == 0)
		{
			free(token);
			continue;
		}
		else if (strcmp(token[0], "stack") == 0)
			mode = 1;
		else if (strcmp(token[0], "queue") == 0)
			mode = 0;
		else if (strcmp(token[0], "push") == 0 && mode == 0)
			exit_status = M_pushq(&stack, token, line_num);
		else if (strcmp(token[0], "push") == 0 && mode == 1)
			exit_status = M_push(&stack, token, line_num);
		else
			exit_status = execute(token, &stack, line_num);
		free(token);
		if (exit_status == EXIT_FAILURE)
			break;
	}
	free_stack(&stack);
	free(line);
	return (exit_status);
}
/**
 * tokening - A function that split the line.
 * @line: The pointer to bytecode line.
 * @delim: Array with 5 delimiters " \n\t\a\b".
 * Return: The pointer to tokens.
 */
char **tokening(char *line, char *delim)
{
	char *tokens = NULL, **token = NULL;
	size_t bufsize = 0;
	int x = 0;

	if (line == NULL || !*line)
		return (NULL);

	bufsize = strlen(line);
	if (bufsize == 0)
		return (NULL);
	token = malloc(bufsize * sizeof(char *));
	if (token == NULL)
	{
		free(line);
		free(token);
		exit(usage_error(0));
	}
	tokens = strtok(line, delim);
	if (tokens == NULL)
	{
		free(token);
		free(line);
		return (NULL);
	}
	while (tokens != NULL)
	{
		token[x] = tokens;
		x++;
		tokens = strtok(NULL, delim);
	}
	token[x] = '\0';
	return (token);
}
/**
 * empty_line - A function that checks if line only contains delimiters.
 * @line: The pointer to the line.
 * @delims: The string with delimiter characters.
 * Return: 1 if the line only contains delimiters, otherwise 0.
 */
int empty_line(char *line, char *delims)
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
