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
	char **argvs;
	char *cmd;
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
/**
 * struct builtin_cmd - struct for built in cmd
 * @cmd: string
 * @f: pointer to func
 * Return: nothing
 */
typedef struct builtin_cmd
{
	char *cmd;
	int (*f)(char **argvs);
}
builtin;

/*lsh*/

void init_shell(error *ptr_error, global *ptr_global);

char *read_command(error *ptr_error);

void execute(char *cmd, char **argvs, error *ptr_error);

char **parse_string(char *cmd, error *ptr_error);

/*non_int*/

void process_pipe(error *ptr_error);

/*check_buidin*/

int check_buildin(char **argvs);

/*_init_*/

void init_var(error *ptr_error, global *ptr_global, int argc, char **argv);

/*string*/

char **_strtrim(char **argvs, char *cmd);

int _strlen(char *s);

/*buitin*/

int  exit_cmd(char **argvs);

int clear_cmd(char **argvs);

int help_cmd(char **argvs);

int cd_cmd(char **argvs);

#endif
