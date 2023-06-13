#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * exec_builtin - execute all command that has to do with the
 * proper working of the shell
 * @str: variable for arrays of strings
 * Return: 0 on success
 */
int exec_builtin(char **str)
{
	int count, state;
	pid_t pd;
	built_in builtin[] = {
		{"exit", my_exit},
		{"env", my_env},
		{NULL, NULL},
	};

	count = 0;
	if (*(str + 0) != NULL)
	{
		while (builtin[count].commands != NULL)
		{
			if (_strcmp(str[0], builtin[count].commands) == 0)
				builtin[count].fptr(str);
			count++;
		}
	}
	return (0);
}
