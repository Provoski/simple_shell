#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "simple_shell.h"

/**
 * main - program entry point
 * Return: 0 on success
 */
int main(void)
{
	char *command, *command_path;
	size_t command_size = 0;
	int i, count_tokens, status, flag;
	char **tokens;
	char *prompt = "($) ";

	i, count_tokens = 0;
	if (!isatty(STDIN_FILENO))
	{
		tokens = get_tokens(command);
		exec_builtin(tokens);
		non_interactive(command);
	}
	else
	{
		while (1)
		{
			write(1, prompt, strlen(prompt));
			if (getline(&command, &command_size, stdin) == -1)
			{
				write(1, "\n", 1);
				free(command);
				break;
			}
			tokens = get_tokens(command);
			exec_builtin(tokens);
			parse_tokens(tokens);
		}
		free_tokens(tokens);
		free(command);
	}
	return (0);
}
