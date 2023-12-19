#include "shell.h"
/**
 * free_dp - free 2d array
 * @command: char**
 * Return: void
 */
void free_dp(char **command)
{
	int i;

	if (!command)
		return;

	for (i = 0; command[i]; i++)
		free(command[i]);

	free(command);
}