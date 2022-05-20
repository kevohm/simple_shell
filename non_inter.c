#include "main.h"
/**
 * process_pipe - pipes input processed here
 * @ptr_error: pointer to error node
 * Return: Nothing
 */
void process_pipe(error *ptr_error)
{
	char *buf = malloc(1024), *cmd = malloc(1024);
	char **argvs;
	size_t len = 1024, i = 0, j = 0;
	ssize_t nread = 0;

	nread = read(0, buf, len);
	if (nread != -1)
	{
		buf = strtok(buf, "\n");
		cmd = buf;
		while (*buf)
		{
			if (*buf == ' ')
				j++;
			i++;
			buf++;
		}
		argvs = parse_string(cmd, ptr_error);
		i =  fork();
		if (i == 0)
		{
			execve(argvs[0], argvs,  NULL);
			exit(1);
		}
		else
		{
			wait(0);
		}
	}
	else
	{
		ptr_error->msg = "getline";
	}
	if (ptr_error->msg != NULL)
	{
		perror(ptr_error->msg);
		exit(0);
	}
	exit(1);
}
