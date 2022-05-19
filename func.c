#include "main.h"

/**
 * init_shell - Initializes shell
 * @void: no params
 * Return: void
 */

void init_shell(void)
{
	while (1)
	{
		char *cmd = malloc(1024);
		char **argvs;

		//printf("#cisfun$ ");
		cmd = read_command();
		argvs = parse_string(cmd);
		execute(cmd, argvs);
	}
}

/**
 * read_command - reads a command from shell
 * @void: no parameters
 * Return: void
 */

char *read_command(void)
{
	char *buff = malloc(1024);
	size_t len = 0;
	int number_read = 0;

	if (buff == NULL)
		return (NULL);
	number_read = getline(&buff, &len, stdin);
	while (number_read != -1)
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
	perror("exit");
	return (NULL);
}

/**
 * parse_string - parse string
 * @cmd: string
 * Return: pointer to string
 * Description: "ls -la ." => {"ls","-la",".",NULL}
 *
 */
char **parse_string(char *cmd)
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
  * Return: Nothing
  */
void execute(char *cmd, char **argvs)
{
	int p_id = fork();

	if (cmd == NULL)
		exit(1);
	if (p_id == -1)
		perror("fork");
	if (p_id == 0)
	{
		execve(cmd, argvs, NULL);
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
