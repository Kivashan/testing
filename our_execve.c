#include "main.h"

int our_execve(char *tokens[], char *environ[])
{
	char *cp_cmd, *path_name, **path_token, *path, *delim = ":";
	int i = 0;

	path = getpath(environ);
	path_token = the_tokeniser(path, delim);
	cp_cmd = stringcpy(tokens[0]);

	while (path_token[i])
	{
		path_name = stringconcat(path_token[i], tokens[i]);
		tokens[0] = path_name;
		execve(tokens[0], tokens, environ);
		i++;
	}
	return (-1);
}
