#include "shell.h"

void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
/**
 * help_unsetenv - function to desplay shellby builtin
 *
 * Return: Nothing
 */
void help_unsetenv(void)
{
	char *message = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, message, _strlen(message));
	message = "enviromental variable. \n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, message, _strlen(message));
	message = "message to stderr.\n";
	write(STDOUT_FILENO, message, _strlen(message));
}
/**
 * help_setenv - function to desplay shellby builtin
 *
 * Return: Nothing
 */
void help_setenv(void)
{
	char *message = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, message, _strlen(message));
	message = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, message, _strlen(message));
	message = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, message, _strlen(message));
}
/**
 * help_env - function to desplay shellby builtin
 *
 * Return: Nothing
 */
void help_env(void)
{
	char *message = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, message, _strlen(message));
}
