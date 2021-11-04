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

int execute(char **argv, char **envp)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("execve ");
		}
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
	return (0);
}

/**
* main- used to bring all functions together
*
* Return: 0
*/

int main(int __attribute__((__unused__))argc, char __attribute__((__unused__))**argv, char **envp)
{
	char *line;
	size_t n = 10;
	char **av;


	for (;;)
	{
		set_prompt();
		if (getline(&line, &n, stdin) == -1)
		{
			break;
		}
		if (line[0] == '\n')
			continue;
		av = tokenize(line); 
		if (_strcmp(av[0], "exit") == 0)
		{
			exit(0);
		}
		if (_strcmp(av[0], "env") == 0)
		{
			env();
		}
		execute(av, envp);
	}
	return (0);
}
