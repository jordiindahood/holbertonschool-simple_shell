#ifndef SIMPLE_SH
#define SIMPLE_SH


/*libraries*/

#include <string.h>
#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**MACROS*/

#define _POSIX_C_SOURCE 200809L
#define DELIMITER " \t\r\n\a"
#define EXIT_TEXT "EXIT"


/*functions for stages of ./hsh program*/

char *hsh_read(void);
char **hsh_parse(char *);
int hsh_exec(char**);


#endif
