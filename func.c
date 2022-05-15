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
		//user@directory$ /bin/ls
		char *user = malloc(20);
		size_t len = 100;
		char *pwd = malloc(len);
		char *cmd = malloc(1024);
	
		user = getenv("USER");
		getcwd(pwd, len);
		printf("%s#%s$ ", user, pwd);
		cmd = read_command();
		execute(cmd);
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
	size_t len = 0, number_read = 0;

	if (buff == NULL)
		return (NULL);
	number_read = getline(&buff, &len, stdin);
	if (number_read != -1)
	{
		buff = strtok(buff, "\n");
		printf("buff %s\n", buff);
		return (buff);
	}
	else
	{
		perror("exit");
		return (NULL);
	}
}
/**
 * execute - execute commands
 * @cmd: command
 * return: Nothing
 *
 */
void execute (char *cmd) //(char *cmd, char *argv[], char **env)
{
	char *env[] = {NULL};
	char *argvs[] = {cmd, NULL};
	int p_id = fork();

	if (p_id == -1)
		perror("fork");
	if (p_id == 0)
	{
		execve(cmd, argvs, NULL);
		_exit(p_id);
	}
	else
	{
		wait(NULL);
	}
}
// parse_string {"ls", "-la", NULL}
// clear
// exit
// cd -> chdir(char *s)
