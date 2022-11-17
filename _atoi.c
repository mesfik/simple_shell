#include "shell.h"

int num_len(int num);
char *_itoa(int num);
int create_error(char **args, int err);
/**
 * _itoa - converts an intiger to a string
 *
 * @num: entry intiger
 *
 * Return: the converted string
 */
char *_itoa(int num)
{
	char *str;
	int ln = num_len(num);
	unsigned int n;

	str = malloc(sizeof(char) * (ln + 1));
	if (!str)
		return (NULL);
	str[ln] = '\0';
	if (num < 0)
	{
		n = num * -1;
		str[0] = '-';
	}
	else
	{
		n = num;
	}
	ln--;
	do {
		str[ln] = (n % 10) + '0';
		n /= 10;
		ln--;
	} while (n > 0);
	return (str);
}
/**
 * num_len - function to count length of the number
 *
 * @num: entry number intiger
 *
 * Return: length
 */
int num_len(int num)
{
	unsigned int n;
	int ln = 1;

	if (num < 0)
	{
		ln++;
		n = num * -1;
	}
	else
	{
		n = num;
	}
	while (n > 9)
	{
		ln++;
		n /= 10;
	}
	return (ln);
}
/**
 * create_error - function to find the error
 *
 * @args: argument variable
 * @err: the error value
 *
 * Return: the error value
 */
int create_error(char **args, int err)
{
	char *error;

	switch (err)
	{
		case -1:
			error = error_env(args);
			break;
		case 1:
			error = error_1(args);
			break;
		case 2:
			if (*(args[0]) == 'e')
				error = error_2_exit(++args);
			else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
				error = error_syntax(args);
			else
				error = error_2_cd(args);
			break;
		case 126:
			error = error_126(args);
			break;
		case 127:
			error = error_127(args);
			break;
	}
	write(STDERR_FILENO, error, _strlen(error));
	if (error)
		free(error);
	return (err);
}

