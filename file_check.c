#include "main.h"

int file_check(char *tokens)
{
	char **path = NULL;
	struct stat st;
	int i = 0, size = 0;

	if (tokens[0] == '/')
	{
		if (stat(tokens, &st) == 0)
			return (0);
		else
			return (-1);
	}

	path = abs_path(tokens);
	while (path[size] != NULL)
		size++;

	while (path[i])
	{
		if (stat(path[i], &st) == 0)
		{
			free_grid(path, size);
			return (0);
		}
		i++;
	}
	
	printf("path[0] = %s\n", path[0]);

	free_grid(path, size);

	return (-1);
}
