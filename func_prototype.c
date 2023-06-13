#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simple_shell.h"

/**
 * _strlen - measures the lenght og a string
 * @str: string pointer
 * Return: lenght of string or 0 if string is NULL
 */
size_t _strlen(const char *str)
{
	int count;

	count = 0;
	if (str == NULL)
		return (0);
	while (*(str + count) != '\0')
		count++;
	return (count);
}

/**
 * _strcpy - copy string from source to destination
 * @dest: pointer to destination
 * @src: pointer to source
 * Return: pointer to destination string;
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
		*(dest + i) = *(src + i);
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strcat - concantenate strings
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: pointer to concantenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, count;

	for (i = 0; *(dest + i); i++)
	{
		if (*(dest + i) == '\0')
		{
			dest[i] = '\n';
			break;
		}
	}
	for (count = 0; *(src + count) != '\0'; count++)
	{
		*(dest + i) = *(src + count);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strcmp - comparei two sring
 * @str1: pointer to first string
 * @str2: pointe to second string
 * Return: 0 if string are same or -1 if they are not
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; (*(str1 + i) != '\0' || *(str2 + i) != '\0'); i++)
		if (*(str1 + i) != *(str2 + i))
			return (-1);
	return (0);
}
