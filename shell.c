#include "main.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/**
* execute- to execute program given to the child
*
* @argv: the command lines it introduces to the program
*
* Return: 0
*/

int execute(char **argv)
{
	pid_t pid;
	int status;
	char *dir;

	dir = get_dir(argv);
	if (access(dir, F_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve ");
				free(argv);
				exit(1);
			}
			exit(0);
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
		}
		else
		{
			perror("Fork ");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("./hsh ");
	}
	return (0);
}

/**
* main- used to bring all functions together
*
* Return: 0
*/

int main(void)
{
	char *line;
	char **av;
	size_t n = 10;


	for (;;)
	{
		set_prompt();
		if (getline(&line, &n, stdin) == -1)
			break;
		if (line[0] == '\n')
			continue;
		av = tokenize(line);
		if (_strcmp(av[0], "exit") == 0)
		{
			free(line);
			free(av);
			exit(0);
		}
		if (_strcmp(av[0], "env") == 0)
		{
			env();
		}
		execute(av);
	}
	return (0);
}
