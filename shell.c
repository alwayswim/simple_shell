#include "main.h"

/**
* execute- to execute the child process
*
* @argv: the command given
*
* @envp: the environment
*
* @sum: the number of prompts printed
*
* Return: 0
*/
int execute(char **argv, char **envp, int sum)
{
	pid_t pid;
	int status;
	char **var;
	char *dir;

	var = get_env("PATH");
	dir = get_file(argv, var);
	if (access(dir, F_OK) == 0)
	{
		pid = fork();
		if (pid  < 0)
		{
			perror("fork ");
		}
		else if (pid == 0)
		{
			if (execve(dir, argv, envp) == -1)
			{
				perror("");
			}
		}
		else
		{
			waitpid(pid, &status, WUNTRACED);
		}
	}
	else
	{
		_perror(argv[0], sum);
	}
	return (0);
}
/**
* main - to create a shell
*
* @argc: unused argument
*
* @argv: unused command line argument
*
* @envp: to compare with environment variable
*
* Return: Always 0.
*/
int main(int argc, char __attribute__((__unused__))**argv, char **envp)
{
	char **av;
	int sum = 0;
	char *line;
	(void)argc;

	signal(SIGINT, signal_handling);
	for (;;)
	{
		set_prompt();
		sum += 1;
		line = get_line();
		av = tokenize(line);
		if (line == NULL)
		{
			return (0);
		}
		if (_strcmp(av[0], "exit") == 0)
		{
			exit(0);
		}
		if (_strcmp(av[0], "env") == 0)
		{
			env_fun();
		}
		execute(av, envp, sum);
	}
	return (0);
}
