#include "monty.h"
/**
 * set_op_tok_error - set last element of Gvar to be an error code.
 * @error_code: intger to store as sting in Gvar.
 */
void set_op_tok_error(int error_code)
{
	int len = 0, x = 0;
	char *exit_s = NULL;
	char **new_var = NULL;

	len = token_arr_len();
	new_var = malloc(sizeof(char *) * (len + 2));
	if (!Gvar)
	{
		malloc_failed();
		return;
	}
	while (x < len)
	{
		new_var[x] = Gvar[x];
		x++;
	}
	exit_s = Gint(error_code);
	if (!exit_s)
	{
		free(new_var);
		malloc_failed();
		return;
	}
	new_var[x++] = exit_s;
	new_var[x] = NULL;
	free(Gvar);
	Gvar = new_var;
}
