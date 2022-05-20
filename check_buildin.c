#include "main.h"
/**
 * check_buildin - check for more functionality
 * @argvs: command
 * Return: integer
 */
int check_buildin(char **argvs)
{
	int i, check = 0;
	builtin arr[] = {
		{"exit", exit_cmd},
		{"cd", cd_cmd},
		{"clear", clear_cmd},
		{"help", help_cmd},
		{NULL, NULL}
	};

	for (i = 0; i < 4; i++)
	{
		if (arr[i].cmd && (argvs[1] == NULL))
		{
			if ((strcmp(arr[i].cmd, argvs[0])) == 0)
				check = arr[i].f(argvs);
		}
	}
	return (check);
}
