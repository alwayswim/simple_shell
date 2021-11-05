#include "main.h"

/**
* _strncmp- to compare the first n bytes fo a string
*
* @s1: string to be compared
*
* @s2: string to be compared
*
* @n: the number of bytes to compare
*
* Return: the diffrence in bytes of the first characters that are different
*/

int _strncmp(const char *s1, const char *s2, int n)
{
	int i;

	i = 0;
	while (*s1 && *s2 && i < n)
	{
		return (*s1 - *s2);
		i++;
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return (0);
}

/**
* _putchar - to print a character
*
* @c: character to be printed
*
* Return: buffer to out put
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _puts - to print a string
*
* @str: string to be printed
*
* Return: nothing
*/

void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
	i++;
	}
	_putchar('\n');
}
/**
 * _strdup - copes a string to another
 * @str: the array
 * Return: pointer of sting copied
 */
char *_strdup(char *str)
{
	int i, j;
	char *dest;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	dest = malloc(sizeof(char *) * i);
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		dest[j] = str[j];
	}
	return (dest);
}
