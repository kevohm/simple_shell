#include "main.h"
/**
 * check_buildin - check for more functionality
 * @cmd: command
 * Return: Nothing
 */
void check_buildin(char *cmd)
{
	write(1, "processing", 11);
	printf("\n%s\n", cmd);
}
