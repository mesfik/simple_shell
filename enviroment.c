#include "shell.h"

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);
/**
 * _getenv - function to find enviromental variable
 *
 * @var: string pointer (name of enviromental var)
 *
 * Return: poiter to enviromental variable
 */
char **_getenv(const char *var)
{
	int i, ln;

	ln = _strlen(var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], ln) == 0)
			return (&environ[i]);
	}
	return (NULL);
}
/**
 * _copyenv - function copy of enviroment
 *
 * Return: pointer to a new copy
 */
char **_copyenv(void)
{
	char **Nenv;
	size_t size = 0;
	int i;

	while (environ[size])
	{
		size++;
	}
	Nenv = malloc(sizeof(char *) * (size + 1));
	if (!Nenv)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		Nenv[i] = malloc(_strlen(environ[i]) + 1);
		if (!Nenv[i])
		{
			for (i--; i >= 0; i--)
				free(Nenv[i]);
			free(Nenv);
			return (NULL);
		}
		_strcpy(Nenv[i], environ[i]);
	}
	Nenv[i] = NULL;
	return (Nenv);
}
/**
 * free_env - frees the enviroment
 *
 * Return: Nuting
 */
void free_env(void)
{
	int i = 0;

	while (environ[i])
	{
		free(environ[i]);
		i++;
	}
	free(environ);
}



