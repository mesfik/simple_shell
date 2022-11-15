#include "shell.h"
void sig_handler(int sig);
int execute(char **args, char **front);

/**
 * sig_handler - a new prompt up on signal
 *
 * @sig: signal
 */
void sig_handler(int sig)
{
	char *Nprom = "\n$ ";

	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, Nprom, 3);
}
/**
 * execute - initial execution function
 *
 * @args: argument of variables
 * @front: pointer to the argument
 *
 * Return: the exit value of the last comand
 */
int execute(char **args, char **front)
{
	pid_t in_pid;
	int status, flag = 0, ret = 0;
	char *comand = args[0];

	if (comand[0] != '/' && comand[0] != '.')
	{
		flag = 1;
		comand = get_location(comand);
	}
	if (!comand || (access(comand, F_OK)) == -1)
	{
		if (errno == EACCES)
			ret = (create_error(args, 126));
		else
			ret = (create_error(args, 127));
	}
	else
	{
		in_pid = fork();
		if (in_pid == -1)
		{
			if (flag)
				free(comand);
			perror("Error initial:");
			return (1);
		}
		if (in_pid == 0)
		{
			execve(comand, args, environ);
			if (errno == EACCES)
				ret = (create_error(args, 126));
			free_env();
			free_args(args, front);
			free_alias_list(aliases);
			_exit(ret);
		}
		else
		{
			wait(&status);
			ret = WEXITSTATUS(status);
		}
	}
	if (flag)
		free(comand);
	return (ret);
}
/**
 * main - UNIX comand interprator
 *
 * @argc: argument count
 * @argv: argument variable
 *
 * Return: executed comand
 */
int main(int argc, char *argv[])
{
	int ret = 0, n;
	int *exe = &n;
	char *prompt = "$ ", *Nline = "\n";

	name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, sig_handler);

	*exe = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);

	if (argc != 1)
	{
		ret = proc_file_commands(argv[1], exe);
		free_env();
		free_alias_list(aliases);
		return (*exe);
	}
	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		ret = handle_args(exe);
		if (ret == END_OF_FILE || ret == EXIT)
		{
			if (ret == END_OF_FILE)
				write(STDOUT_FILENO, Nline, 1);
			free_env();
			free_alias_list(aliases);
			exit(*exe);
		}
	}
	free_env();
	free_alias_list(aliases);
	return (*exe);
}
