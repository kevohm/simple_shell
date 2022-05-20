#include "main.h"
/**
 * main - body function
 * @argc: integer
 * @argv: array of strings
 * Return: 0
 */
int main(int argc, char **argv)
{
	error *ptr_error, error_cmd;
	global *ptr_global, global_cmd;

	ptr_error = &error_cmd;
	ptr_global = &global_cmd;
	init_var(ptr_error, ptr_global, argc, argv);
	init_shell(ptr_error, ptr_global);

	if (!ptr_error->status)
	{
		perror(ptr_error->msg);
		exit(ptr_error->status);
	}
	return (0);
}
