#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * remove_newline - removes new line character from a string
 * @str: pointer to string
 * Return: 0 on success.
 */
int remove_newline(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
	return (0);
}

/**
 * free_tokens - free memory allocated for tokens
 * @tokens: pointer to token
 * Return: None;
 */
void free_tokens(char **tokens)
{
	int i, token_count;

	token_count = 0;
	for (i = 0; i < token_count; i++)
		free(tokens[i]);
	free(tokens);
}

/**
 * _getline - get command from stdin
 * @lineptr:
 * @n:
 * @stream:
 * Return: number of character read on success
 */

