#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *blah;
	size_t a = 1024;
	blah = malloc(sizeof(char) * a);
	while (1)
	{
		printf("$ ");
		getline(&blah, &a, stdin);
		
		/* we need to use a while loop to catch the single and double quotes*/
		char *token = strtok(blah, " ");
		while (token)
		{
			printf("%s\n", token);
			token = strtok(NULL, " ");
		}
	}

	return (0);
}


