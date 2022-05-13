#include "main.h"

/**
 * init_shell - Initializes shell
 * @void: no parameters
 * Return: void
 */

void init_shell(void)
{
	while (1)
	{
		printf("#");
		read_command();
	}
}

/**
 * read_command - reads a command from shell
 * @void: no parameters
 * Return: void
 */

void read_command(void)
{
	char *buff;
	size_t len = 0, number_read = 0;

	number_read = getline(&buff, &len, stdin);
	if (number_read != -1)
	{
		char *arg[] = {buff, NULL};

		printf("buff %s\n", buff);
		if((execve(buff, arg, NULL)) == -1)
		{
			perror("./shell");
		}
		else
		{
			printf("output ...");
		}
	}
	else
	{
		perror("exit");
	}
}
void execute (char *cmd)
{
	char *env[] = {NULL};
	char *argvs[] = {cmd, NULL};

	execve(cmd, argvs, NULL);
}
