#include "monty.h"

char **Gvar = NULL;
/**
 * main - interpreter for Monty ByteCodes files.
 * @argc: is the number of arg count
 * @argv: is the enterd arg.
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	FILE *OFile;
	int Sexit = EXIT_SUCCESS;

	if (argc != 2)
		return (use_errors());
	OFile = fopen(argv[1], "r");
	if (OFile == NULL)
		return (open_error(argv[1]));
	Sexit = R_monty(OFile);
	fclose(OFile);
	return (Sexit);
}
