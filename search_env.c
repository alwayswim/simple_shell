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
	char *rmv, *path, *new_name;
	char **rm;

	len = _strlen(name);
	i = 0;
	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			path = environ[i];
			j = 0;
			rm = malloc(sizeof(char *) * 15);
			new_name = _strdup(path);
			rmv = strtok(new_name, "=:");
			while (rmv != NULL)
			{
				rm[j] = rmv;
				j++;
				rmv = strtok(NULL, "=:");
			}
			rm[j] = NULL;
		}
	i++;
	}
	return (rm);
}
/**
* get_stat - to check if file exists
*
* @argv: command given
*
* @path: the environment variable given
*
* Return: the path
*/
int get_stat(char **argv, char **path)
{
	int m;
	char *cmd;

	for (m = 0; path[m] != NULL; m++)
	{
		cmd = _strcat(path[m], "/");
		cmd = _strcat(path[m], argv[0]);
		if (access(cmd, F_OK) == 0)
		{
			argv[0] = cmd;
			break;
		}
	}
	return (0);
}
