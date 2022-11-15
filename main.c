#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * main - program entry point
 * Return: 0 on success
 */
int main(void)
{
	init_shell();
	return (0);
}
