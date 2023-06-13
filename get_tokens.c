#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * get_tokens - it splint strings of command
 * gotten from get_line funtion into array
 * of individual strings using strtok() funtion
 * @str: variable for the collected strings of command
 * Return: arrays of splinted strings
 */
char **get_tokens(char *str)
{
	char *token;
	char **tokens;
	char *delim = " \n\t";
	int count;

	count = 0;
	tokens =  malloc(sizeof(char *) * MAX_TOKENS);
	if (!tokens)
	{
		perror("error");
		exit(1);
	}
	token  = strtok(str, delim);
	while (token != NULL)
	{
		/*strcpy(*(tokens + count), token);*/
		tokens[count] = malloc((_strlen(token) + 1) * sizeof(char));
		if (!tokens[count])
		{
			perror("error");
			exit(1);
		}
		_strcpy(tokens[count], token);
		count++;
		if (count > MAX_TOKENS)
		{
			perror("error");
			break;
		}
		token = strtok(NULL, delim);
	}
	return (tokens);
}
