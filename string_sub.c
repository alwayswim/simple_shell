#include "main.h"

/**
*
*
*
*
*
*
*
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - fnction to concatenate a string to another string
 *
 * @dest: string to concatenate to
 *
 * @src: string to concatenate from
 *
 * Return: Destination string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/**
 * _strlen - to know the length of a string
 *
 * @src: the string to be checked
 *
 * Return: The length
 */

int _strlen(char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - compares teh contents of a string
 *
 * @s1: string to be compared
 *
 * @s2: string to be compared
 *
 * Return: the byte of the first string minus the second
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

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

int _strncmp(char *s1, char *s2, int n)
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
