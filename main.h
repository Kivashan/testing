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

char **the_tokeniser(char *, char *);
int our_execve(char **, char **);

#endif
