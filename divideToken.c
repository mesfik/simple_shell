#include "shell.h"

int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * token_len - function to locate delimeter index
 *
 * @str: string pointer
 * @delim: the delimeter character
 *
 * Return: delimeter index pointed to the string
 */
int token_len(char *str, char *delim)
{
	int i, ln = 0;

	for (i = 0; str[i] && str[i] != *delim; i++)
	{
		ln++;
	}
	return (ln);
}
/**
 * count_tokens - function to count the delimeter
 *
 * @str: string pointer
 * @delim: the delimeter character
 *
 * Return: the number of character that are on the string
 */
int count_tokens(char *str, char *delim)
{
	int i, token = 0, ln = 0;

	for (i = 0; str[i]; i++)
	{
		ln++;
	}
	for (i = 0; i < ln; i++)
	{
		if (str[i] != *delim)
		{
			token++;
			i += token_len(str + i, delim);
		}
	}
	return (token);
}
/**
 * _strtok - function to toknize a string
 *
 * @line: pointer to the string
 *
 * Return: array that counts the toknize
 */
char **_strtok(char *line, char *delim)
{
	char **ptr;
	int i = 0, token, t, letters, l;

	token = count_tokens(line, delim);
	if (token == 0)
		return (NULL);
	ptr = malloc(sizeof(char *) * (token + 2));
	if (!ptr)
		return (NULL);
	for (t = 0; t < token; t++)
	{
		while (line[i] == *delim)
			i++;
		letters = token_len(line + i, delim);
		ptr[t] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[t])
		{
			for (i -= 1; i > 0; i++)
				free(ptr[i]);
			free(ptr);
			return (NULL);
		}
		for (l = 0; l < letters; l++)
		{
			ptr[t][l] = line[i];
			i++;
		}
		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}

