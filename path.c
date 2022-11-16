#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"
#include <fcntl.h>
#include <sys/stat.h>

/**
 * search_path - search for the executable of command in directory
 * @str: command to search
 * Return: pointer to path where command executable is located
 * on success or command[str] if not file im any path
 */
char *search_path(char *str)
{
	struct stat file;
	int i, len;
	char *real_path;
	char *paths[] = {
		"/usr/local/bin/",
		"/usr/bin/",
		"/bin/",
		NULL,
	};


	for (i = 0; paths[i] != NULL; i++)
	{
		len = (strlen(str) + strlen(paths[i]));
		real_path = malloc(sizeof(char) * (len + 1));
		if (!real_path)
			perror("malloc");
		strcat(real_path, paths[i]);
		strcat(real_path, str);
		if (stat(real_path, &file) >= 0)
		{
			return (real_path);
		}
		free(real_path);
	}
	return (str);
}
