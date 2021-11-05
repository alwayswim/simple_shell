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
* search_env - searches environment variables for path
*
* Return: pointer to PATH
*/

char **search_env()
{
	int i, len;
	char **path;
	char *name;

	name = "PATH";
	len = _strlen(name);
	i = 0;
	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			path = get_dir(environ[i]);
		}
	i++;
	}
	return (path);
}

/**
* get_dir - to get the directories of the path
*
* @path: the pointer to the path
*
* Return: the directory list
*/
char **get_dir(char *path)
{
	int k = 0;
	char **rm;
	char *rmv, *new_path = NULL;


	rm = malloc(sizeof(char *) * 15);
	if (path == NULL)
	{
		free(path);
		return (0);
	}
	if (rm == NULL)
	{
		free(path);
		return (0);
	}
	new_path = _strdup(path);
	rmv = strtok(new_path, "=:");
	while (rmv != NULL)
	{
		rm[k] = rmv;
		k++;
		rmv = strtok(NULL, "=:");
	}
	rm[k] = NULL;
	return (rm);
}
/**
* get_stat- to check the status of a concatenated command
*
* @argv: command given
*
* @path: the path directories
*
* Return: 0
*
*/
int get_stat(char **argv, char **path)
{
	char *concat = NULL, *dir = NULL;
	int i;
	struct stat sb;

	if (path == NULL)
	{
		free(path);
		free(argv);
	}
	for (i = 0; path[i] != NULL ; i++)
	{
		concat = _strcat(path[i], "/");
		dir = _strcat(concat, argv[0]);
		if (stat(dir, &sb) == 0 && (sb.st_mode & S_IXUSR))
		{
			argv[0] = dir;
			free(path);
			free(path[0]);
			break;
		}
	}
	free(path[0]);
	return (0);
}
