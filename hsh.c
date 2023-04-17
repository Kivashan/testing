#include "main.h"

int main(int argc, char *argv[], char *envp[])
{
	char *cmd;
	int retval, retvale = 0, pid, status;
	size_t bytes = 1024;
	char **tokens;
	char *delim = " ";
	extern char **environ;
	char *tmp;

	while(1)
	{
		int i = 0;

		get_prompt();
		cmd = malloc(sizeof(char) * bytes);
		if (!cmd)
			return (-1);
		retval = getline(&cmd, &bytes, stdin);
	/*	retval = our_getline(&cmd, &bytes, STDIN_FILENO);*/
		if (retval == -1)
			_puts("Error reading command line");
		cmd[stringlen(cmd) - 1] = '\0';
		tmp = stringcpy(cmd);
		tokens = the_tokeniser(cmd, delim);
		if (file_check(tokens, environ) == 0)
		{
			printf("This is the main process\n");
			pid = fork();
			if (pid == -1)
                        {
                                perror("Error:");
                                return (1);
                        }
			else if (pid == 0)
				retvale = our_execve(tokens, environ);
			else
				wait(&status);
		}
		else
			cmd_not_found_error(tokens[0]); /* error message to match linux */
	}

	return (0);
}
