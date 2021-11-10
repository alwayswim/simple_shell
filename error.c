#include "main.h"

/**
* _perror- to print error for commands not found
*
* @argv: the command given
*
* @sum: the number of times command was executed
*
* Return: 0
*/

int _perror(char *argv, int sum)
{
	char *num;

	num = to_string(sum, 10);
	write(STDOUT_FILENO, "./hsh", 5);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, num, _strlen(num));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, argv, _strlen(argv));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
	return (0);
}
/**
* to_string - to change integer to string
*
* @num: thenumber to be converted
*
* @base: the base
*
* Return: the string
*/
char *to_string(int num, int base)
{
	int temp, i = 0, j;
	char *str;

	str = malloc(sizeof(char) * 10);
	if (str == NULL)
	{
		return (0);
	}
	if (num < 1)
	{
		return (0);
	}
	else
	{
		while (num != 0)
		{
			temp = num % base;
			str[i] = temp + '0';
			i++;
			num = num / base;
		}
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(str[i]);
	}
	return (str);
}
