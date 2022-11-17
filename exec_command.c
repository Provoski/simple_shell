#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * exec_command - execute all command that has to do with the
 * proper working of the shell
 * @str: variable for arrays of strings
 * Return: 1 on success
 */
int exec_command(char **str)
{
	int count, state;
	built_in builtin[] = {
		{"exit", my_exit},
		{"env", my_env},
		{NULL, NULL},
	};
	count = 0;
	state = 0;
	if (str[0] != NULL)
	{
		while (builtin[count].commands != NULL)
		{
			if (strcmp(str[0], builtin[count].commands) == 0)
			{
				builtin[count].fptr(str);
				state = 1;
			}
			count++;
		}
	}
	if (state != 1)
	{
		parse_tokens(str);
	}
	return (1);
}
