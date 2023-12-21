#include "shell.h"
/**
 * hsh_read- Read a line of input from stdin
 *	
 * Return: string on success or null if error  
*/
char *hsh_read(void)
{
	ssize_t n;
	size_t len = 0;
	char *buf = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	n = getline(&buf, &len, stdin);
	if (n == -1)
	{
		free(buf), buf = NULL;
		return (NULL);
	}
	return (buf);
}