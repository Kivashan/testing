#include "main.h"

int our_execve(char *tokens[], char *environ[])
{
	execve(tokens[0], tokens, environ);
	return (-1);
}
