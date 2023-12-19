#include "shell.h"

int main(int argc __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	int state = 1;
	char **command;
	char *line;

	do
	{
		/*print prompt*/
		printf("$ ");

		/*READ*/
		line = hsh_read();

		/*skip to loop if nothing printed*/
		if (line && line[0] != '\n')
		{
			/*EXIT: if "exit" command is written properly in stdin*/
			if (strncmp(line, "exit", 4) == 0 && line)
			{
				free(line);
				break;
			}
			/*PARSE*/
			command = hsh_parse(line);

			/*EXECUTE*/
			state = hsh_exec(command, env);

			/*memory leaks aren't allowed :) */
			free_dp(command);
		}
	} while (state);

	/*exit in a success state*/
	return (EXIT_SUCCESS);
}
