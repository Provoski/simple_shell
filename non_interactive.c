#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "simple_shell.h"


/**
 * non_interactive - program entry point
 * @command: pointer to passed commad
 * Return: 0 on success
 */
int non_interactive(char *command)
{
	char **tokens = NULL;
	size_t command_size;
	int i, count_tokens, status;
	char **env = NULL;
	pid_t pd;

	env = environ;
	i, count_tokens = 0;
	pd = fork();
	if (pd == 0)
	{
		getline(&command, &command_size, stdin);
		tokens = get_tokens(command);
		for (i = 0; *(tokens + i) != NULL; i++)
			count_tokens++;
		if (strcmp(command, "exit") == 0)
			exit(EXIT_SUCCESS);
		if (strcmp(command, "env") == 0)
		{
			for ( ; *env != NULL; env++)
				write(1, *env, strlen(*env));
		}
		if (execve(*(tokens + 0), tokens, environ) == -1)
		{
			perror(*(tokens + 0));
			free_tokens(tokens);
			return (-1);
		}
	}
	else
		wait(NULL);
	free_tokens(tokens);
	return (0);
}
