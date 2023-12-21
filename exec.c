#include "shell.h"
#include <unistd.h>
/**
 * hsh_exec- excute a function
 * @command: char
 * @env: array of char
 * @idx: int
 * Return: int
*/
int hsh_exec(char **command, char *env[],int idx)
{
	pid_t pid;
	int status;
	char *command_with_path;

	(void)idx;

	command_with_path = _getpath(command[0]);

	if (!command_with_path)
	{
		perror("FAIL IN (_getpath)");
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
			if (command_with_path)
				free(command_with_path), command_with_path = NULL;
		}
	}
	else
	{
		/*Parent process*/
		waitpid(pid, &status, 0);
		free_dp(command), command = NULL;
	}
	return (WEXITSTATUS(status));
}
