#include "monty.h"
/**
 * main - The entry point function for Monty Interpreter.
 * @ac: The number of arguments.
 * @av: The pointer to an array of inputed arguments.
 * Return: Always 0 (on Success).
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;
	int exit_stat = EXIT_SUCCESS;

	if (ac != 2)
		return (usage_error(1));

	fd = fopen(av[1], "r");
	if (fd == NULL)
		return (open_error(av[1]));

	exit_stat = M_run(fd);
	fclose(fd);
	return (exit_stat);
		open_error(av[1]);
	M_run(fd);
	exit(EXIT_SUCCESS);
	return (0);
}
