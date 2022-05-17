#ifndef MAIN_H
#define MAIN_H

//include

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h> //strtok
#include <sys/wait.h> //wait

//functions

void init_shell();

char *read_command();

void execute(char *cmd);

char **parse_string(char *cmd);

#endif 
