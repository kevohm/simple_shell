#include "main.h"


/**
 * init_var - initialize initial variables
 * @ptr_error: pointer to error node
 * @ptr_global: pointer to global node
 * @argc: no args
 * @argv: args
 * return: Nothing
 */
void init_var(error *ptr_error, global *ptr_global, int argc, char **argv)
{
	ptr_error->status = 0;
	ptr_error->msg = NULL;
	ptr_global->argv = argv;
	ptr_global->argc = argc;
	ptr_global->argvs = NULL;
	ptr_global->cmd = NULL;
}
