#include "main.h"

int main(int argc, char *argv[], char *envp[])
{
	char *cmd;
	char *prompt = "$";
	int retval, retvale = 0;
	size_t bytes = 1024;
	char **tokens;
	char *delim = " ";
	extern char **environ;
	char *tmp;

	while(1)
	{
		int i = 0;

		_puts(prompt);
		cmd = malloc(sizeof(char) * bytes);
		if (!cmd)
			return (-1);
		retval = getline(&cmd, &bytes, stdin);
		if (retval == -1)
			_puts("Error reading command line");
		cmd[stringlen(cmd) - 1] = '\0';
		_puts(cmd);
		tmp = stringcpy(cmd);
		tokens = the_tokeniser(cmd, delim);
	
		retvale = execve(tokens[0], tokens, environ);
	//	retvale = our_execve(tokens, environ);
		
/*		check the error on linux and modify our error message*/
		if (retvale == -1)
			_puts("Command not found\n");

	/*	while (tokens[i])
		{
			_puts(tokens[i]);
			_putchar('\n');
			i++;
		}
		*/
	}

	return (0);
}
