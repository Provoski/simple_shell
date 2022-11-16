#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define MAX_ARGS 10
#define MAX_CHAR 50

extern char **environ;

void init_shell(void);
char **get_tokens(char *str);
int exec_command(char **str);
int parse_tokens(char **str);
char *get_line(void);
int check_alias(char **str);
char *search_path(char *str);

int my_exit(char **str);
int my_env(char **str);


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
