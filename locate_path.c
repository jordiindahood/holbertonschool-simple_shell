#include "shell.h"
#include <unistd.h>
char *_getpath(char *command)
{

	char *the_path, *the_real_command, *directory;
	struct stat state;
	int i;

	/*case1: command with full path, example (/bin/ls)*/
	i = 0;
	while (command[i])
	{
		if (command[i] == '/')
		{
			if (stat(command, &state) == 0)
			{
				return (command);
			}
			return (NULL);
		}
		i++;
	}

	/*case2: command without path, example(whoami)*/
	the_path = _getenv("PATH");
	if (the_path == NULL || the_path[0] == '\0')
		return (NULL);

	directory = strtok(the_path, ":");
	while (directory)
	{
		the_real_command = malloc(strlen(directory) + strlen(command) + 2);

		if (the_real_command != NULL)
		{
			snprintf(the_real_command, strlen(directory) + strlen(command) + 2, "%s/%s", directory, command);
			if (stat(the_real_command, &state) == 0)
			{
				free(the_path), the_path = NULL;
				return (the_real_command);
			}
			free(the_real_command), the_real_command = NULL;
			directory = strtok(NULL, ":");
		}
		else
		{
			free(the_path), the_path = NULL;
			return NULL;
		}
	}
		free(the_path), the_path = NULL;
	return (NULL);
}
