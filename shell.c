#include "main.h"

/**
* execute- to execute the child process
*
* @argv: the command given
*
* @envp: the environment
*
* @get_stat: the status of command when concatenated
*
* Return: 0
*/
int execute(char **argv, char **envp, int get_stat)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid  < 0)
	{
		perror("fork ");
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("./hsh ");
		}
		exit(0);
	}
	else
	{
		if (get_stat == 0)
		{
			waitpid(pid, &status, WUNTRACED);
		}
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
	char **av, **var;
	int dir = 0;
	char *line;
	(void)argc;

	signal(SIGINT, signal_handling);
	for (;;)
	{
		set_prompt();
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
		else
		{
			var = get_env("PATH");
			dir = get_stat(av, var);
			execute(av, envp, dir);
		}
		free(line);
		free(av);
	}
	return (0);
}
