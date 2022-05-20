#include "simple_shell.h"

/**
 * sharpie_setenv - calls the setenv function with correct parameters
 * @arrtok: the array of tokens to be passed
 * Return: Always 0.
 */
int sharpie_setenv(char **arrtok)
{
	int i;

	for (i = 0; arrtok[i]; i++)
		;

	if (i != 3)
	{
		write(1, "Error: Wrong amount of arguments\n", 35);
		return (0);
	}

	_setenv(arrtok[1], arrtok[2], 1);

	return (0);
}
