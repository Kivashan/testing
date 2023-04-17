#include "main.h"
#include <sys/types.h>
#include <dirent.h>

int file_finder(char *tokens[], char *environ[])
{
//	char *cp1, *cp2, *path_name, **path_token, *delim = ":", *filename;
//	int len = 0, pos = 0, len2 = 0;
	char **path_token, *filename, *delim = ":", *cp1;
	int i = 0;
	DIR *fd;
	struct dirent *entry;

	path_token = the_tokeniser(getpath(environ), delim);
	cp1 = stringcpy(tokens[0]);
//	cp2 = stringcpy(tokens[0]);

	while (path_token[i] != NULL)
	{
		fd = opendir(path_token[i]);
		if (fd == NULL)
			return (-1);
		while ((entry = readdir(fd)) != NULL)
		{
			if ((strcmp(entry->d_name, cp1)) == 0)
			{
				return (0);
			}
		}
		closedir(fd);
		i++;
	}
	return (-1);
}
