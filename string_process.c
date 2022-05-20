#include "main.h"
/**
 * _strlen - get size of string
 * @s: string
 * Return: integer
 */
int _strlen(char *s)
{
	char *buf = s;
	int len = 0;

	while (*buf)
	{
		len++;
		buf++;
	}
	return (len);
}
/**
 * _strtrim - convert to array
 * @argvs: array of strings
 * @cmd: string
 * Return: array of strings
 */
char **_strtrim(char **argvs, char *cmd)
{
	char *buf, *ptr;
	int len = 0, i = 0;

	buf = ptr = strtok(cmd, " ");

	while (ptr != NULL)
	{
		len = 0;
		while (*ptr)
		{
			len++;
			ptr++;
		}
		argvs[i] = malloc((sizeof(char)) * (len + 1));
		argvs[i] = buf;
		buf = ptr = strtok(NULL, " ");
		i++;
	}
	argvs[i] = buf;
	cmd = argvs[0];
	return (argvs);
}
