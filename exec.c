#include "shell.h"
#include <unistd.h>
int hsh_exec(char **command, char *env[])
{
	pid_t pid;
	int status;
	char *command_with_path;

	command_with_path = _getpath(command[0]);
	if (!command_with_path)
	{
		perror("FAIL IN (_getpath)");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		/*Child process*/
		if (execve(command_with_path, command, env) == -1)
		{
			perror("hsh fail ");
			free(command_with_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*Parent process*/
		waitpid(pid, &status, 0);
	}
	free(command_with_path);
	return (1);
}
