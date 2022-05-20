#include "main.h"

/**
 * init_shell - Initializes shell
 * @ptr_error: pointer to error node
 * @ptr_global: pointer to global node
 * Return: void
 */

void init_shell(error *ptr_error, global *ptr_global)
{
	if (ptr_global->argc > 1)
	{
		printf("finished");
	}
	if (!isatty(STDIN_FILENO))
	{
		process_pipe(ptr_error);
	}
	else
	{
	while (1)
	{
		char *cmd = malloc(1024);
		char **argvs;

		cmd = read_command(ptr_error);
		argvs = parse_string(cmd, ptr_error);
		execute(cmd, argvs, ptr_error);
	}
	}
}

/**
 * read_command - reads a command from shell
 * @ptr_error: pointer to error node
 * Return: void
 */

char *read_command(error *ptr_error)
{
	char *buff = malloc(1024);
	size_t len = 0;
	int number_read = 0;

	write(1, "#cisfun$ ", 10);
	if (buff == NULL)
	{
		ptr_error->msg = "malloc";
		return (NULL);
	}
	number_read = getline(&buff, &len, stdin);
	if (number_read != -1)
	{
		buff = strtok(buff, "\n");
		if (feof(stdin) == -1)
		{
			return (NULL);
		}
		if (strcmp(buff, "exit") == 0)
		{
			exit(1);
		}
		return (buff);
	}
	else
	{
		ptr_error->msg = "getline";
	}
	return (NULL);
}

/**
 * parse_string - parse string
 * @cmd: string
 * @ptr_error: pointer to error node
 * Return: pointer to string
 * Description: "ls -la ." => {"ls","-la",".",NULL}
 *
 */
char **parse_string(char *cmd, error *ptr_error)
{
	char **argvs;
	char *ptr = cmd;
	char *buf;
	int len = 0, i = 0;

	if (cmd == NULL)
	{
		return (NULL);
	}
	while (*ptr)
	{
		if (*ptr == ' ')
			len++;
		ptr++;
	}
	argvs = malloc((sizeof(char *)) * (len + 1));
	if (argvs == NULL)
	{
		free(argvs);
		free(cmd);
		ptr_error->msg = "malloc";
		return (NULL);
	}
	buf = ptr = strtok(cmd, " ");
	while (ptr != NULL)
	{
		len = 0;
		while (*ptr)
		{
			len++;
			ptr++;
		}
		argvs[i] = malloc((sizeof(char)) * (len + 1));
		argvs[i] = buf;
		buf = ptr = strtok(NULL, " ");
		i++;
	}
	argvs[i] = buf;
	cmd = argvs[0];
	return (argvs);
}

/**
  * execute - execute commands
  * @cmd: command "ls"
  * @argvs: array of arguements{"ls",args...,NULL}
  * @ptr_error: pointer to error node
  * Return: Nothing
  */
void execute(char *cmd, char **argvs, error *ptr_error)
{
	int p_id = fork();

	if (ptr_error->msg != NULL)
	{
		ptr_error->status = 0;
		return;
	}
	check_buildin(cmd);
	if (p_id == -1)
	{
		ptr_error->msg = "fork";
		ptr_error->status = 0;
		return;
	}
	if (p_id == 0)
	{
		if (execve(cmd, argvs, NULL))
		{
			ptr_error->msg = "execve";
		}
		exit(1);
	}
	else
	{
		wait(NULL);
	}
	if (ptr_error->msg != NULL)
	{
		ptr_error->status = 0;
	}
}
