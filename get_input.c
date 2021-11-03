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
* tokenize - create substring of a given string
*
* @line: the line to be used
*
* Return: pointer to teh array of strings
*/
char **tokenize(char *line)
{
	int i, len, j = 10;
	char **tok;
	char *token;

	len = _strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	tok = malloc(sizeof(char *) * j);
	if (tok == NULL)
	{
		free(tok);
		return (0);
	}
	i = 0;
	token = strtok(line, " ");
	while (token != NULL)
	{
		tok[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	tok[i] = NULL;
	return (tok);
}
