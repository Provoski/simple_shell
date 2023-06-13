#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * my_exit - exit the shell program
 * @str: array of strings
 * Return: Nothing.
 */
int my_exit(char **str)
{
	if (strcmp(str[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/**
 * my_env - prints environmetal variable of the current enviroment
 * @str: array of strings
 * Return: 0 on success
 */
int my_env(char **str)
{
	int i;
	(void)(str);

	while (*environ != NULL)
	{
		write(1, *environ, strlen(*environ));
		write(1, "\n", 1);
		environ++;
	}
	return (0);
}
