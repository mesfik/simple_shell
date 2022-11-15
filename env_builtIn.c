#include "shell.h"

int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);

/**
 * shellby_setenv -function that adds or sets variable to path
 *
 * @args: argument variable
 * @front: pointer to the bigining
 *
 * Description: args[1] is the name of the new or existing PATH variable
 *              args[2] is the value to set the new or changed variable to
 * Return: 0 Success if error -1
 */
int shellby_setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL, **Nenv, *Nvalue;
	size_t size = 0;
	int i;

	if (!args[0] || !args[1])
		return (create_error(args, -1));
	Nvalue = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!Nvalue)
		return (create_error(args, -1));
	_strcpy(Nvalue, args[0]);
	_strcat(Nvalue, "=");
	_strcat(Nvalue, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = Nvalue;
		return (0);
	}
	while (environ[size])
	{
		size++;
	}
	Nenv = malloc(sizeof(char *) * (size + 2));
	if (!Nenv)
	{
		free(Nvalue);
		return (create_error(args, -1));
	}
	for (i = 0; environ[i]; i++)
	{
		Nenv[i] = environ[i];
	}
	free(environ);
	environ = Nenv;
	environ[i] = Nvalue;
	environ[i + 1] = NULL;
	return (0);
}
/**
 * shellby_unsetenv - function to delete enviroment path
 *
 * @args: argument variable
 * @front: pointer to the bigining
 *
 * Description: args[1] is the PATH variable to remove
 *
 * Return: 0 Success if error -1
 */
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var, **Nenv;
	size_t size = 0;
	int i, j;

	if (!args[0])
		return (create_error(args, -1));
	env_var = _getenv(args[0]);
	if (!env_var)
		return (0);
	while (environ[size])
	{
		size++;
	}
	Nenv = malloc(sizeof(char *) * size);
	if (!Nenv)
		return (create_error(args, -1));
	for (i = 0, j = 0; environ[i]; i++)
	{
		if (*env_var == environ[i])
		{
			free(*env_var);
			continue;
		}
		Nenv[j] = environ[i];
		j++;
	}
	free(environ);
	environ = Nenv;
	environ[size - 1] = NULL;

	return (0);
}
/**
 * shellby_env - function that prints current enviroment
 *
 * @args: argument variable
 * @front: pointer to the bigining
 *
 * Description: Prints one variable per
 *
 * Return: 0 Success if error -1
 */
int shellby_env(char **args, char __attribute__((__unused__)) **front)
{
	int i = 0;
	char n = '\n';

	if (!environ)
		return (-1);
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, &n, 1);
		i++;
	}
	(void)args;
	return (0);
}
