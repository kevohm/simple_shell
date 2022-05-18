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
		char **argvs;
	
		user = getenv("USER");
		getcwd(pwd, len);
		printf("[%s@%s]$ ", user, pwd);
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
	size_t len = 0, number_read = 0;

	if (buff == NULL)
		return (NULL);
	number_read = getline(&buff, &len, stdin);
	if (number_read != -1)
	{
		buff = strtok(buff, "\n");
		//printf("buff %s\n", buff);
		return (buff);
	}
	else
	{
		perror("exit");
		return (NULL);
	}
}

/**
 * parse_string - parse string
 * @cmd: string
 * Return: pointer to string{"ls","-la",".",NULL} cmd = "/bin/ls"
 *
 */
char **parse_string(char *cmd)
{
	char **argvs;
	char *ptr = cmd;
	char *buf;
	int len = 0, i = 0;

	//strtok "my name is" *(cmd++)
	//{"john","mark","felix"} 
	// \0 = 0
	while (*ptr)
	{
		if (*ptr == ' ')
			len++;
		ptr++;
	}
	argvs = malloc((sizeof(char *)) * (len + 1));// {"d","c"}
	buf = ptr = strtok(cmd," ");
	while (ptr != NULL)
	{
		len = 0;
		while (*ptr)//string\0 *ptr = s
		{
			len++;
			ptr++;
		}
		argvs[i] = malloc((sizeof(char)) * (len + 1));
		argvs[i] = buf;
		//printf("PTR: %s size: %d\n", buf, len);
		buf = ptr = strtok(NULL, " ");
		i++;
	}
	argvs[i] = buf;
	cmd = argvs[0];
	return (argvs);
}

/*
 * execute - execute commands
 * @cmd: command
 * return: Nothing
 *
 */
void execute (char *cmd, char **argvs) //(char *cmd, char *argv[], char **env)
{
	int p_id = fork();
	char *path = "/bin/";
	char *ptr = malloc(1024), *buf;

	//add path
	buf = argvs[0];
	cmd = ptr;
	while(*path)
	{
		*(ptr++) = *(path++);
	}
	while(*buf)
	{
		*(ptr++) = *(buf++);
	}	
	argvs[0] = cmd;
	//printf("cmd: %s argvs: %s\n",cmd ,argvs[0]);
	//execute /bin/ls -la
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
// parse_string {"ls", "-la", NULL}
// ls
// clear
// exit
// cd -> chdir(char *s)

