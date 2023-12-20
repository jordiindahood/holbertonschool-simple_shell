#ifndef SIMPLE_SH
#define SIMPLE_SH

/*libraries*/

#include <string.h>
#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/**MACROS*/

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#define DELIMITER " \t\n"
#define EXIT_TEXT "EXIT"

extern char **environ;
/*functions for stages of ./hsh program*/

char *hsh_read(void);
char **hsh_parse(char *);
int hsh_exec(char **, char **, int);

/*functions for built-in*/
void handle_built_in(char **command, int *status, int idx, char **av);
void hsh_cd(char **cmd, int *status, int idx, char **av);
void hsh_exit(char **cmd, int *status);
void hsh_env(char **cmd, int *status);
int is_built_in(char **command);

char *_getenv(char *var);
char *_getpath(char *);
void free_dp(char **command);

#endif
