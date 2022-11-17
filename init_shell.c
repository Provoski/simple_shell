#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * init_shell - initialize the shell command
 * and get commands using the getline function
 * Return: Nothing
 */
void init_shell(void)
{
	char *line;
	char **toks_args;
	size_t state;

	do {
		write(1, "($) ", 4);
		line = get_line();
		toks_args = get_tokens(line);
		state = exec_command(toks_args);
		free(line);
		free(toks_args);
	} while (state == 1);
}
