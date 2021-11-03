#include "main.h"

/**
* env - to print the environment variables
*
* Return: 0.
**/

int env(void)
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
* search_env - searches environment variables and creates 2 strings
*              of the name and value
*
* @name: the name of the variable to be searched
*
* Return: pointer to the array of strings
*/

char **search_env(const char *name)
{
	int i, j, len;
	char *rmv, *path;
	char **rm;

	len = _strlen(name);
	i = 0;
	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			path = environ[i];
			j = 0;
			rm = malloc(sizeof(char *) * 2);
			if (rm  == NULL)
			{
				perror("Error in allocating memory");
				return (0);
			}
			rmv = strtok(path, "=");
			while (rmv != NULL)
			{
				rm[j] = rmv;
				j++;
				rmv = strtok(NULL, "=");
			}
			rm[j] = NULL;
		}
	i++;
	}
	return (rm);
}

/**
* get_dir - to get the directory of the command given and the concatenate
*	    it with its directory
*
* @av: the command given
*
* Return: the path to the command
*/
char *get_dir(char **av)
{
	int l, k = 0;
	char **rm, **tok;
	char *direct, *token, *cwd = getcwd(NULL, 0);
	struct stat st;
	const char *res;

	rm = search_env("PATH");
	tok = malloc(sizeof(char *) * 10);
	if (tok == NULL)
	{
		return (0);
		free(tok);
	}
	direct = rm[1];
	token = strtok(direct, ":");
	while (token != NULL)
	{
		tok[k] = token;
		k++;
		token = strtok(NULL, ":");
	}
	tok[k] = NULL;
	for (l = 0; l < k && tok != NULL; l++)
	{
		res = tok[l];
		if (chdir(res) == 0)
		{
			if (stat(av[0], &st) == 0)
			{
				tok[l] = _strcat(tok[l], "/");
				av[0] = _strcat(tok[l], av[0]);
				break;
			}
		}
	}
	chdir(cwd);
	return (av[0]);
}
