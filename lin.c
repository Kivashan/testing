#include <stdio.h>
#include <stdlib.h>
int len(char *str);

int main(int argc, char *argv, char *envp)
{
	extern char **environ;
	int i = 0, j = 0, location = 0, length, k = 0;
	char *test = "PATH=";
	char *newPath;

	while (environ[i])
	{
		j = 0;
		while (test[j] == environ[i][j])
		{
			if (j == 4)
			{
				location = i;
				break;
			}
			j++;
		}
		if (j == 4)
			break;
		i++;
	}
	printf("%s\n", environ[location]);

	length = len(environ[location]) - j + 1;
	newPath = malloc(sizeof(char) * length);

	for (k = 0; k < length; k++, j++)
	{
		newPath[k] = environ[i][j + 1];
	}

	printf("%s\n", newPath);

	

	return 0;
}

int len(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return i;
}
	
