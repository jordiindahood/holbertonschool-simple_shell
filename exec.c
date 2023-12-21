#include "shell.h"
#include <unistd.h>
/**
 * hsh_exec- excute a function
 * @command: char
 * @env: array of char
 * @idx: int
 * @av: char**
 * Return: int
 */
int hsh_exec(char **command, char *env[], int idx, char **av)
{
	pid_t pid;
	int status;
	char *command_with_path;

	command_with_path = _getpath(command[0]);

	if (!command_with_path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", av[0], idx, command[0]);
		if (command)
			free_dp(command), command = NULL;
		exit(127);
	}

	pid = fork();
	if (pid == 0)
	{
		/*Child process*/
		if (execve(command_with_path, command, env) == -1)
		{
			fprintf(stderr, "%s fail ", av[0]);
			free_dp(command), command = NULL;
		}
	}
	else
	{
		/*Parent process*/
		waitpid(pid, &status, 0);
		if (strcmp(command_with_path, command[0]) != 0)
			free(command_with_path), command_with_path = NULL;
		free_dp(command), command = NULL;
	}
	return (WEXITSTATUS(status));
}
