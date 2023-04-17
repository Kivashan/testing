#include "main.h"

int main(int argc, char *argv[], char *envp[])
{
	char *cmd;
	char *prompt = "$ ";
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
		tmp = stringcpy(cmd);
		tokens = the_tokeniser(cmd, delim);
		if (file_check(tokens, environ) == 0)	
			retvale = our_execve(tokens, environ);
		else
			cmd_not_found_error(tokens[0]); /* error message to match linux */
	}

	return (0);
}
