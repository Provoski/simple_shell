#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * get_line - get command from the shell using getline function here
 * Return: strings of users command
 */
char *get_line(void)
{
	char *buffer;
	size_t buffer_size;

	buffer = NULL;
	buffer_size = 0;
	if (getline(&buffer, &buffer_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (buffer);
	free(buffer);
}

