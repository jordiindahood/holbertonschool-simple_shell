#include "shell.h"
#include <unistd.h>
/**
 * _getpath- locate the path
 * @command: *char
 * Return: string
 */
char *_getpath(char *command)
{
	char *the_path, *the_real_command, *directory;
	struct stat state;

	/*case1: command with full path, example (/bin/ls)*/

	if (if_command_with_path(command))
		return (if_command_with_path(command));

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
			strcpy(the_real_command, directory);
			strcat(the_real_command, "/");
			strcat(the_real_command, command);
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
			return (NULL);
		}
	}
	free(the_path), the_path = NULL;
	return (NULL);
}
/**
 * if_command_with_path- checking
 * @command: *char
 * Return: string
 */
char *if_command_with_path(char *command)
{
	struct stat state;
	int i = 0;

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
	return (NULL);
}
