#include "main.h"
#include <sys/types.h>
#include <dirent.h>


void get_filename(char *cp_cmd, char *filename, int len, int *pos);

int file_check(char *tokens[], char *environ[])
{
	char *cp_cmd, *cp_cmd2, *path_name, **path_token, *path, *delim = ":", *filename;
	int i = 0, len = 0, pos = 0, len2 = 0;
	DIR *fd;
	struct dirent *entry;

	path = getpath(environ);
	path_token = the_tokeniser(path, delim);
	cp_cmd = stringcpy(tokens[0]);
	cp_cmd2 = stringcpy(tokens[0]);
	len = stringlen(cp_cmd2);

	if (cp_cmd[0] == '/')
	{
		i = len - 1;

		while (cp_cmd2[i] != '/')
		{
			cp_cmd2[i] = '\0';
			i--;
			len2++;
			printf("%d\n", len2);
		}
		printf("%s\n", cp_cmd2);
		filename = malloc(sizeof(char) * (len2 + 1));
		get_filename(cp_cmd, filename, len - 1, &pos);
                filename[pos] = '\0';
		_puts(filename);
		_putchar('\n');
		fd = opendir(cp_cmd2);
		if (fd == NULL)
			return (-1);
		i = 0;
		while ((entry = readdir(fd)) != NULL)
		{
			if ((strcmp(entry->d_name, "ls")) == 0)
			{
				return (0);
			}
		}
		closedir(fd);
	}
	return (-1);
}
void get_filename(char *cp_cmd, char *filename, int len, int *pos)
{
	if (cp_cmd[len] != '/')
	{
		filename[*pos] = cp_cmd[len];
		*pos++;
		get_filename(cp_cmd, filename, --len, pos);
	}
}
