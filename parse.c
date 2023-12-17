#include "shell.h"
char **hsh_parse(char *line)
{
	int size = 1024, pos = 0;
	char **tokens = malloc(size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "error at allocation");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMITER);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= size)
		{
			size += 1024;
			tokens = realloc(tokens, size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIMITER);
	}
	tokens[pos] = NULL;
	return tokens;
}
