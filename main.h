#ifndef MAIN_H
#define MAIN_H

//include
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

//functions
void init_shell();
void read_command();
void execute(char*cmd);
void parse_string();

#endif 
