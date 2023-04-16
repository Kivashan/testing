#include "main.h"

int our_execve(char *tokens[], char *environ[])
{
	int retval;

	retval = execve(tokens[0], tokens, environ);

	return ((retval == -1) ? retval : 0);
}
