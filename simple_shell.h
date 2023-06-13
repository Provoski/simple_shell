#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define MAX_TOKENS 100
#define MAX_CHAR 50
#define MAX_COMMAND_LENGTH 100
#define BUFFER_SIZE 1024

extern char **environ;

void init_shell(void);
char **get_tokens(char *str);
int exec_builtin(char **str);
int parse_tokens(char **str);
char *get_line(void);
int check_alias(char **str);
char *search_path(char *str);

int my_exit(char **str);
int my_env(char **str);
int remove_newline(char *str);
void free_tokens(char **tokens);
int non_interactive(char *command);
int interactive(char *command, int i);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
int _strcmp( char *str1, char *str2);
int _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * struct built_in - for comparing and executing built in commands
 * @commands: strings to chech whick command to execute
 * @fptr: a pointer associated to command
 * Description: create a data type that compare and execute
 * a built in function associated to a particular alias name
 */
typedef struct built_in
{
	char *commands;
	int (*fptr)(char **str);
} built_in;


#endif
