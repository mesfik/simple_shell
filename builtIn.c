#include "shell.h"

int shellby_alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
/**
 * set_alias - function set existing alias
 *
 * @var_name: name of the alias
 * @value: value of the name alias
 *
 * Return: Nothing
 */
void set_alias(char *var_name, char *value)
{
	alias_t *temp = aliases;
	int ln, i, j;
	char *Nvalue;

	*value = '\0';
	value++;
	ln = _strlen(value) - _strspn(value, "'\"");
	Nvalue = malloc(sizeof(char) * (ln + 1));
	if (!Nvalue)
		return;
	for (i = 0, j = 0; value[i]; i++)
	{
		if (value[i] != '\'' && value[i] != '"')
			Nvalue[j++] = value[i];
	}
	Nvalue[j] = '\0';
	while (temp)
	{
		if (_strcmp(var_name, temp->name) == 0)
		{
			free(temp->value);
			temp->value = Nvalue;
			break;
		}
		temp = temp->next;
	}
	if (!temp)
		add_alias_end(&aliases, var_name, Nvalue);
}
/**
 * shellby_alias - function prints aliases
 *
 * @args: argument of an array
 * @front: pointer to the argument
 *
 * Return: 0 if success or -1
 */
int shellby_alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *temp = aliases;
	int k = 0, ret = 0;
	char *value;

	if (!args[0])
	{
		while (temp)
		{
			print_alias(temp);
			temp = temp->next;
		}
		return (ret);
	}
	while (args[k])
	{
		temp = aliases;
		value = _strchr(args[k], '=');
		if (!value)
		{
			while (temp)
			{
				if (_strcmp(args[k], temp->name) == 0)
				{
					print_alias(temp);
					break;
				}
				temp = temp->next;
			}
			if (!temp)
				ret = create_error(args + k, 1);
		}
		else
			set_alias(args[k], value);
		k++;
	}
	return (ret);
}
/**
 * print_alias - function that print alias
 *
 * @alias: alias pointer
 *
 * Return: Nothing
 */
void print_alias(alias_t *alias)
{
	char *alias_string;
	int ln = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (ln + 1));
	if (!alias_string)
		return;
	_strcpy(alias_string, alias->name);
	_strcat(alias_string, "='");
	_strcat(alias_string, alias->value);
	_strcat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, ln);
	free(alias_string);
}
/**
 * replace_aliases - function to replace matching aliases
 *
 * @args: argument variable pointer
 *
 * Return: pointer to the argument
 */
char **replace_aliases(char **args)
{
	alias_t *temp;
	int i;
	char *Nvalue;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (i = 0; args[i]; i++)
	{
		temp = aliases;
		while (temp)
		{
			if (_strcmp(args[i], temp->name) == 0)
			{
				Nvalue = malloc(sizeof(char) * (_strlen(temp->value) + 1));
				if (!Nvalue)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(Nvalue, temp->value);
				free(args[i]);
				args[i] = Nvalue;
				i--;
				break;
			}
			temp = temp->next;
		}
	}
	return (args);
}
