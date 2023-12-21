#include "shell.h"
#include <unistd.h>
/**
 * hsh_exec- excute a function
 * @command: char
 * @env: array of char
 * @idx: int
 * Return: int
 */
int hsh_exec(char **command, char *env[], int idx)
{
	pid_t pid;
	int status;
	char *command_with_path;

	(void)idx;

	command_with_path = _getpath(command[0]);

	if (!command_with_path)
	{
		fprintf(stderr, "./hsh: %d %s: not found\n", idx, command[0]);
		if (command)
			free_dp(command), command = NULL;
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		/*Child process*/
		if (execve(command_with_path, command, env) == -1)
		{
			perror("hsh fail ");
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
