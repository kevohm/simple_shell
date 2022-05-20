#include "simple_shell.h"

/**
 * sharpie_cd - Changes the user's current directory.
 * @arrtok: the directory to be changed to
 * Return: 0 on success, 1 on failure.
 */
int sharpie_cd(char **arrtok)
{
	(void)arrtok;
	return (0);
}

/**
 * sharpie_env - Prints the user's global environment variable.
 * @arrtok: An unused string.
 * Return: 0 on success, 1 on failure.
 */
int sharpie_env(char **arrtok)
{
	int i, len;

	(void)arrtok;
	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(1, "\n", 1);
	}
	return (0);
}

/**
 * sharpie_exit - Exits the user's shell.
 * @arrtok: An unused string.
 * Return: 0 on success, 1 on failure.
 */
int sharpie_exit(char **arrtok)
{
	(void)arrtok;
	return (1);
}
