#include "shell.h"

/**
 * builtin_execute - executes the built in functions
 * @tokens: arguments being passed
 * Return: tokens
 */
int builtin_execute(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int i;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{"cd", my_chdir},
		{NULL, NULL}
	};
	if (tokens[0] == NULL)
		return (1);
	length = _strlen(tokens[0]);

	num = shell_num_builtins(builtin);
	for (i = 0; i < num; i++)
	{
		if (_strcmp(tokens[0], builtin[i].name, length) == 0)
		{
			status = (builtin[i].p)(tokens);
			return (status);
		}
	}
	return (1);
}
/**
 * shell_num_builtins - this check num built-ins
 * @builtin: takes the builtin to be counted
 * Return: num of built-ins
 */

int shell_num_builtins(built_s builtin[])
{
	unsigned int i;

	i = 0;
	while (builtin[i].name != NULL)
		i++;
	return (i);
}
#include "shell.h"
/**
 * shell_exit - exits the shell
 * @cmd: arguments being passed
 * Return: void
 */
int shell_exit(char **cmd __attribute__((unused)))
{
	return (-1);
}
/**
 * shell_env - prints environment
 * @cmd: arguments being passed
 * Return: void
 */
int shell_env(char **cmd __attribute__((unused)))
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
/**
 * my_chdir - builtin function
 * @cmd: command
 * Return: void
 */
int my_chdir(char **cmd)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	if (!strcmp(cmd[0], cwd))
		if (chdir(cmd[1]) == -1)
			perror("Error");
	return (0);
}
