#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"

/**
 * _getline - it read command from file stream
 * @lineptr: 
 * @n:
 * @stream:
 * Return:
 **/
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufferSize = *n;
	char *buffer = *lineptr;
	char *newBuffer;
	int c;
	size_t i;

	i = 0;
	if (buffer == NULL || bufferSize < BUFFER_SIZE)
	{
		buffer = (char *)malloc(BUFFER_SIZE);
		if (!buffer)
			return (-1);
		bufferSize = BUFFER_SIZE;
	}
	while (c = fgetc(stream))
	{
		if (1 >= bufferSize - 1)
		{
			bufferSize += BUFFER_SIZE;
			newBuffer = (char *)realloc(buffer, bufferSize);
			if (!newBuffer)
				return (-1);
			buffer = newBuffer;
		}
		buffer[i++] = (char)c;
		if (c == '\n')
			break;
	}
	if (i == 0)
		return (-1);
	buffer[i] = '\0';
	*lineptr = buffer;
	*n = bufferSize;
	return (int)i;

}
