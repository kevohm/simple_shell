#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void init_shell(char **argv);

char *read_command(void);

void execute(char *cmd, char **argvs);

char **parse_string(char *cmd);

#endif
