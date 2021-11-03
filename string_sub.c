#include "main.h"

/**
 * _strcpy - to copy string from source to destination
 *
 * @dest: destination to be copied to
 *
 * @src: origin to be copied from
 *
 * Return: destination string
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

int _strlen(const char *src)
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

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
* _strncat - to concatenate only n bytes
*
* @dest: destination for concatenation
*
* @src: source of concatenation
*
* @n: number of bytes to concatenate
*
* Return: Destination
*/

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; src[j] != '\0' && j < n; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}
