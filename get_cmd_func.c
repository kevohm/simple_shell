#include "simple_shell.h"

/**
 * get_cmd_func - If possible, retrieves the function that corresponds
 * to a built-in command such as 'env' or 'exit'.
 * @s: the string to be compared with list of known built-in commands
 *
 * Return: The corresponding function if one is found, otherwise NULL.
 */
int (*get_cmd_func(char *s))(char **arrtok)
{
	built_t cmds[] = {
	{"env", sharpie_env},
	{"setenv", sharpie_setenv},
	{"unsetenv", sharpie_setenv},
	{"cd", sharpie_cd},
	{"exit", sharpie_exit},
	{NULL, NULL}
	};
	int i = 0;

	while (cmds[i].cmd)
	{
		if (_strcmp(s, cmds[i].cmd))
			return (cmds[i].f);
		i++;
	}

	return (cmds[i].f);
}
