#include "main.h"

/**
* env_fun - to print the environment variables
*
* Return: 0.
*/

int env_fun(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		_puts(environ[i]);
	i++;
	}
	return (0);
}

/**
* get_env - to get value of an environment variable
*
* @name: the name of environment variable
*
* Return: pointer to the value
*/

char **get_env(char *name)
{
	int i, len, j;
	char *rmv, *path;
	char **rm;

	len = _strlen(name);
	i = 0;
	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			path = _strdup(environ[i]);
			j = 0;
			rm = malloc(sizeof(char *) * 15);
			rmv = strtok(path, "=:");
			while (rmv != NULL)
			{
				rm[j] = _strdup(rmv);
				j++;
				rmv = strtok(NULL, "=:");
				free(rm[j]);
			}
			rm[j] = NULL;
			free(path);
			free(rm[j]);
		}
		free(rm[j]);
	i++;
	}
	free(rm[j]);
	return (rm);
}
/**
* get_file - to check if file exists
*
* @argv: command given
*
* @path: the environment variable given
*
* Return: the path
*/
char *get_file(char **argv, char **path)
{
	int m;
	char *cmd;

	if (path == NULL)
	{
		free(path);
		free(argv);
		return (0);
	}
	for (m = 0; path[m] != NULL; m++)
	{
		cmd = _strcat(path[m], "/");
		cmd = _strcat(cmd, argv[0]);
		if (access(cmd, F_OK) == 0)
		{
			argv[0] = cmd;
			free(path[0]);
			free(path);
		}
	}
	return (argv[0]);
}
