#include "shell.h"

int main()
{
	/*INIT*/
	int state;
	char **command;
	char *line;

	do {
		/*print prompt*/
		printf("$ ");
		/*READ*/
		line = hsh_read();

		/*PARSE*/
		command = hsh_parse(line);

		/*EXECUTE*/
		state = hsh_exec(state);

		/*memory leaks aren't allowed :) */
		free(line);
		free(command);
	} while (state);

	/*exit in a success state*/
	return (EXIT_SUCCESS);
}
