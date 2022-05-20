#include "main.h"

/**
 * exit_cmd - exit function
 * @argvs: array of string
 * Return: integer
 */
int exit_cmd(char **argvs)
{
	if (argvs[1] != NULL)
	{
		return (0);
	}
	return (2);
}
/**
 * clear_cmd - clear screen
 * @argvs: array of string
 * Return: integer
 */
int clear_cmd(char **argvs)
{
	if (argvs[1] != NULL)
	{
		return (0);
	}
	if ((write(1, "\033[2J", 7)) != -1)
	{
		return (1);
	}
	return (0);
}
/**
 * cd_cmd - chamge directory
 * @argvs: array of string
 * Return: integer
 */
int cd_cmd(char **argvs)
{
	if (argvs[1])
	{
		chdir(argvs[1]);
		return (1);
	}
	perror("cd");
	return (0);
}
/**
 * help_cmd - print out help
 * @argvs: array of string
 * Return: Nothing
 */
int help_cmd(char **argvs)
{
	if (argvs[1] !=  NULL)
	{
		return (0);
	}
	printf("========== BUILTIN COMMANDS =======\n");
	printf("\t1.) cd\n");
	printf("\t2.) exit\n");
	printf("\t3.) clear\n");
	printf("\t4.) help\n");
	return (1);
}
