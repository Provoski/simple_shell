#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
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
	int fd;
	pid_t pid;

	if (str[0] != NULL)
	{
		fd = 0;
		fd = open(str[0], O_RDONLY);
		if (fd == -1)
		{
			perror(str[0]);
			return (-1);
		}
		pid = fork();
		if (pid == 0)
		{
			if (execve(str[0], str, NULL) == -1)
				perror(str[0]);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror(str[0]);
		else
		{
			wait(NULL);
		}
		close(fd);
	}
	return (1);
}
