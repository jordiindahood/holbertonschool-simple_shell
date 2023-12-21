#include "shell.h"
/**
 * main - entry point
 * @ac: int
 * @av: char
 * Return: int
*/

int main(__attribute__((unused)) int ac, char **av)
{
	int state = 1, index = 0;
	char **command;
	char *line;

	do
	{
		/*READ*/
		line = hsh_read();
		/*interactive mode*/
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		index++;
		/*skip to loop if nothing printed*/

		/*EXIT: if "exit" command is written properly in stdin*/
		if (strncmp(line, "exit", 4) == 0 && line)
		{
			free(line), line = NULL;
			exit(EXIT_SUCCESS);
		}

		/*PARSE*/
		command = hsh_parse(line);

		/*EXECUTE*/
		if (!command)
			continue;
		if (is_built_in(command) == 1)
			handle_built_in(command, &state, index, av);
		else
			state = hsh_exec(command, av, index);

	} while (1);

	/*return state*/
	return (state);
}
