#include "shell.h"
char *hsh_read(void)
{
	char *line = NULL;
	int *bufsize = 1024;

	if (getline(&line, bufsize, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS); /*exit as sucess*/
		else
		{
			perror("readline");
			exit(EXIT_FAILURE); /*exit as fail*/
		}
	}

	return (line);
}