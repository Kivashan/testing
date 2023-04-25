#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int get_prompt(void);
void getline_error_handler(char *);
char **word_split(char *str, char *delim);
int no_of_args(char *str, char *delim);
void free_grid(char **grid, int height);
char *_strdup(char *str);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_getenv(char *var);
char *_strconcat(char *str1, char *str2);
char **waymaker(int *i);
char **abs_path(char *token[]);
int file_check(char *tokens[]);

#endif
