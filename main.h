#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int _putchar(char);
int _puts(char *);
int stringlen(char *);
char *stringcpy(char *);
int no_of_args(char *, char *);
char *stringconcat(char *str1, char *str2);
char *getpath(char **envr);

char **the_tokeniser(char *, char *);
int our_execve(char **, char **);

void get_filename(char *cp_cmd, char *filename, int len, int *pos);
int file_check(char *tokens[], char *environ[]);

#endif
