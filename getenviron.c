#include "shell.h"
/**
 * _getenv- returns the value of env
 * @var: *char
 * Return: *char
*/
char *_getenv(char *var)
{
    char *tmp, *value, *key, *env;
    int i;

    for (i = 0; environ[i]; i++)
    {
        tmp = strdup(environ[i]);
        key = strtok(tmp, "=");
        if (key != NULL && strcmp(key, var) == 0)
        {
            value = strtok(NULL, "\n");
            env = (value != NULL) ? strdup(value) : NULL;
                free(tmp), tmp = NULL;
            return (env);
        }
        free(tmp), tmp = NULL;
    }
    return (NULL);
}
