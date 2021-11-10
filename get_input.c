#include "main.h"

/**
* set_prompt - to print the prompt on screen
*
* No return Value
*/

void set_prompt(void)
{
	int i;
	char *prompt = "$ ";

	i = isatty(STDIN_FILENO);
	if (i == 1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
}

/**
* get_line - to get input from the terminal and then store it in string
*
* Return: the input in string form
*/

char *get_line(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t character;
	int i;

	character = getline(&line, &n, stdin);
	if (character == -1)
	{
		i = isatty(STDIN_FILENO);
		if (i == 1)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		return (0);
	}
	if (character == 1)
	{
		free(line);
		return (0);
	}
	return (line);
}
/**
* tokenize - create substring of a given string
*
* @line: the line to be used
*
* Return: pointer to teh array of strings
*/
char **tokenize(char *line)
{
	int i, size = 50;
	char **tok;
	char *token;

	if (line == NULL)
	{
		return (0);
	}
	tok = malloc(sizeof(char *) * size);
	i = 0;
	token = strtok(line, " \n");
	while (token != NULL)
	{
		tok[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	tok[i] = NULL;
	return (tok);
}
/**
* signal_handling - to wait for signal ctrl + c then to
*		    print a newline and promp
*
* @signal: the signal to be sent
*
* Return: Nothing
*/

void signal_handling(int __attribute__((__unused__))signal)
{
	char *prompt = "\n$ ";

	write(STDOUT_FILENO, prompt, _strlen(prompt));
}
