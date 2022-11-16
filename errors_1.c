#include "shell.h"

char *error_126(char **args);
char *error_127(char **args);
/**
 * error_126 - function for error of permission
 *
 * @args: argument variable
 *
 * Return: error
 */
char *error_126(char **args)
{
	char *error, *str;
	int ln;

	str = _itoa(hist);
	if (!str)
		return (NULL);
	ln = _strlen(name) + _strlen(str) + _strlen(args[0]) + 24;
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
	_strcat(error, ": permission denied\n");

	free(str);
	return (NULL);
}
/**
 * error_127 - function for error of permission
 *
 * @args: argument variable
 *
 * Return: error
 */
char *error_127(char **args)
{
	char *error, *str;
	int ln;

	str = _itoa(hist);
	if (!str)
		return (NULL);

	ln = _strlen(name) + _strlen(str) + _strlen(args[0]) + 16;
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
	_strcat(error, ": not found\n");

	free(str);
	return (error);
}

