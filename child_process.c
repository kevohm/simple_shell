#include "simple_shell.h"

/**
 * child_proc - processes input if child_pid == 0
 * @estat: the struct handeling exit status
 * @ar: the array of tokens containing input
 * @cpy2: the input stored as a character pointer
 * @ipname: the name of our shell
 * Return: Struct handeling exit codes.
 */
exit_t *child_proc(exit_t *estat, char **ar, char *cpy2, char *ipname)
{
		if (ar[0] == NULL || *(ar[0]) == '\0')
		{
			_free(3, ar[0], cpy2, ar);
			estat = change_status(estat, NULL, estat->code, 1);
			return (estat);
		}
		if (execve(ar[0], ar, environ) == -1)
		{
			_free(3, ar[0], cpy2, ar);
			perror(ipname);
			estat = change_status(estat, NULL, 127, 1);
			return (estat);
		}

	return (estat);
}
