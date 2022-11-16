#include "shell.h"

char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_syntax(char **args);
/**
 * error_1 - function create errors
 *
 * @args: argument variable
 *
 * Return: error
 */
char *error_1(char **args)
{
	char *error;
	int ln;

	ln = _strlen(name) + _strlen(args[0]) + 13;
	error = malloc(sizeof(char) * (ln + 1));
	if (!error)
		return (NULL);
	_strcpy(error, "alias: ");
	_strcat(error, args[0]);
	_strcat(error, " not found\n");

	return (error);
}
/**
 * error_2_cd - function for error of shellby cd
 *
 * @args: argument variable
 *
 * Return: error cd
 */
char *error_2_cd(char **args)
{
	char *error, *str;
	int ln;

	if (args[0][0] == '-')
	{
		args[0][2] = '\0';
	}
	ln = _strlen(name) + _strlen(str) + _strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (ln + 1));
	str = _itoa(hist);
	if (!str)
		return (NULL);
	if (!error)
	{
		free(str);
		return (NULL);
	}
	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, str);
	if (args[0][0] == '-')
		_strcat(error, ": cd: Illegal option ");
	else
		_strcat(error, ": cd: can't cd to ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(str);
	return (error);
}
/**
 * error_2_exit - function for an error if shellby_exit
 *
 * @args: argument variable
 *
 * Return: error
 */
char *error_2_exit(char **args)
{
	char *error, *str;
	int ln;

	str = _itoa(hist);
	if (!str)
		return (NULL);
	ln = _strlen(name) + _strlen(str) + _strlen(args[0]) + 27;
	error = malloc(sizeof(char) * (ln + 1));
	if (!error)
	{
		free(str);
		return (NULL);
	}
	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, str);
	_strcat(error, ": exit: illegal number: ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(str);
	return (error);
}
/**
 * error_syntax - function for error of syntax
 *
 * @args: argument variable
 *
 * Return: error
 */
char *error_syntax(char **args)
{
	char *error, *str;
	int ln;

	str = _itoa(hist);
	if (!str)
		return (NULL);
	ln = _strlen(name) + _strlen(str) + _strlen(args[0]) + 33;
	error = malloc(sizeof(char) * (ln + 1));
	if (!error)
	{
		free(str);
		return (NULL);
	}
	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, ": Syntax error: \"");
	_strcat(error, args[0]);
	_strcat(error, "\" unexpected\n");

	free(str);
	return (error);
}
/**
 * error_env - function for error of enviroment
 *
 * @args: argument variable
 *
 * Return: error
 */
char *error_env(char **args)
{
	char *error, *str;
	int ln;

	str = _itoa(hist);
	if (!str)
		return (NULL);

	args--;
	ln = _strlen(name) + _strlen(str) + _strlen(args[0]) + 45;
	error = malloc(sizeof(char) * (ln + 1));

	if (!error)
	{
		free(str);
		return (NULL);
	}
	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": Unable to add/remove from enviroment\n");

	free(str);
	return (error);
}
