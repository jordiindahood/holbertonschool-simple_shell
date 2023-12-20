#include "shell.h"

int is_built_in(char **command)

{
	char *built[] = {"exit", "env", "cd", "help", NULL};
	int i;
	for (i = 0; built[i]; i++)
	{
		if (strcmp(command[0], built[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
void handle_built_in(char **command, int *status, int idx, char **av)
{
	if (strcmp(command[0], "exit") == 0)
	{
		hsh_exit(command, status);
	}
	else if (strcmp(command[0], "env") == 0)
	{
		hsh_env(command, status);
	}
	else if (strcmp(command[0], "cd") == 0)
	{
		hsh_cd(command, status, idx, av);
	}
}

void hsh_exit(char **cmd, int *status)
{
	free_dp(cmd);
	exit(*status);
}
void hsh_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	free_dp(cmd);
	(*status) = 0;
}
void hsh_cd(char **cmd, int *status, int idx, char **av)
{
	(*status) = 0;
	if (strcmp(cmd[1], "") == 0)
	{
		if (chdir("/") == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", av[0], idx, cmd[0]);
			(*status) = 0;
		}
	}
	else
	{
		if (chdir(cmd[1]) == -1)
		{
			fprintf(stderr, "%s: %d: %s: can't cd to %s\n", av[0], idx, cmd[0], cmd[1]);
			(*status) = 0;
		}
	}

	free_dp(cmd);
}