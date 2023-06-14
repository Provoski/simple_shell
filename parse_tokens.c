#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "simple_shell.h"

/**
 * parse_tokens - parse tokens to execve funtion and built in functions
 * @str: variable for arrays of strings
 * Return: 1 on success
 */
int parse_tokens(char **str)
{
	int status;
	struct stat st;
	pid_t pid;

	if (*(str + 0) != NULL)
	{
		if (stat(search_path(*(str + 0)), &st))
			perror(*(str + 0));
		else
		{
			pid = fork();
			if (pid == 0)
			{
				execve(search_path(*(str + 0)), str, environ);
				perror(*(str + 0));
				_exit(EXIT_FAILURE);
			}
			else if (pid < 0)
				perror(*(str + 0));
			else
			{
				waitpid(pid, &status, 0);
			}
		}
	}
	return (1);
}

