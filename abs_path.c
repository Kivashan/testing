#include "main.h"

char **abs_path(char *token)
{
	int i = 0, len = 0, j = 0, k = 0, l = 0;
	char **absolute_path = NULL, **path = NULL;
	
	path = waymaker(&i);
	absolute_path = malloc(sizeof(char *) * i);
	if (!absolute_path)
		return (NULL);

	while (j < i)
	{
		k = 0;
		l = 0;
		len = _strlen(path[j]) + _strlen(token) + 2;
		absolute_path[j] = malloc(sizeof(char) * len);
		if (!(absolute_path[j]))
			return (NULL);

		while (path[j][k])
		{
			absolute_path[j][k] = path[j][k];
			k++;
		}
		absolute_path[j][k++] = '/';
		while (token[l])
		{
			absolute_path[j][k] = token[l];
			k++;
			l++;
		}
		absolute_path[j][k] = '\0';
		j++;
	}
	absolute_path[j] = NULL;
	free_grid(path, i);
	return (absolute_path);

}	