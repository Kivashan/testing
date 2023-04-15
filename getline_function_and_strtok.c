#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **tokeniser(char *str, char *delim);
int no_of_cmd_args(char *str, char *delim);
int len_of_str(char *str);




int main(int argc, char *argv[], char *envp[])
{
	char *blah;
	size_t a = 1024;
	char *delim = " ";
	int check = 50;
	char *envir = "/usr/bin";

	blah = malloc(sizeof(char) * a);
	while (1)
	{
		printf("$ ");
		getline(&blah, &a, stdin);
		
		char **token = tokeniser(blah, delim);
		
		printf("check 10\n");	
		check = execve(token[0], token, &envir);
		printf("check 11 = %d\n", check);

	}

	return (0);
}

char **tokeniser(char *str, char *delim)
{
	char **token; /*an array of pointers to hold tokens*/
	char *tmp;
	int args = no_of_cmd_args(str, delim);
	int flag = 0;
	int len = 0;
	int i = 0;

	token = malloc(sizeof(*token) * (args + 1));
	printf("check 2\n");

	for (i = 0; i < args; i++)
	{
		printf("check 7\n");
		if (flag == 0)
		{
			tmp = strtok(str, delim);
			flag = 1;
		}
		else
			tmp = strtok(NULL, delim);

		printf("check 8\n");
		len = len_of_str(tmp);
		printf("check 8.1\n");
		token[i] = malloc(sizeof(char) * len);
		
		token[i] = tmp;
		printf("check 9\n");
	}
	token[i] = NULL;
	printf("check 5\n");
	return (token);

}
/* returns no of args in the cmd string*/
int no_of_cmd_args(char *str, char *delim)
{
	int args = 0;
	char *token;
	
	printf("check 3\n");
	while (1)
	{
		/*additionally add check to see if there is a single or double quote*/
		if (args == 0)
		{
			token = strtok(str, delim);
		}
		else
			token = strtok(NULL, delim);
		if (!token)
			break;
		args++;
	}
	printf("check 4 = %d\n", args);
	return (args);
}
/* calculates length of token*/
int len_of_str(char *str)
{
	int i = 0;
	
	printf("check 6\n");
	while(str[i])
		i++;

	return (i);
}
