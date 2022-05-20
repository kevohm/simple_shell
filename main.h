#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * struct global_var - global
 * @argv: argv
 * @argc: argc
 * Return: nothing
 */
typedef struct global_var
{
	char **argv;
	int argc;
}
global;
/**
 * struct error_cmd - error
 * @msg: string
 * @status: integer
 * Return: nothing
 */
typedef struct error_cmd
{
	char *msg;
	int status;
}
error;

void init_shell(error *ptr_error, global *ptr_global);

char *read_command(error *ptr_error);

void execute(char *cmd, char **argvs, error *ptr_error);

char **parse_string(char *cmd, error *ptr_error);

void process_pipe(error *ptr_error);

void check_buildin(char *cmd);

void init_var(error *ptr_error, global *ptr_global, int argc, char **argv);

char **_strtrim(char **argvs, char *cmd);

int _strlen(char *s);

#endif
