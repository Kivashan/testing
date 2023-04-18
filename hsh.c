#include "main.h"

int main(int argc __attribute__((unused)),
	       	char *argv[] __attribute__((unused)), char *envp[])
{
	char *cmd = NULL;
	int retval, retvale = 0, pid, status, int_mode = 1;
	size_t bytes;/* can later assign value if getline does not work properly */
	char **tokens;
	char *delim = " ";
	extern char **environ;
	char *tmp;

	while(1)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode)
		{
			int i = 0;
			get_prompt();
			/*cmd = malloc(sizeof(char) * bytes);
			if (!cmd)
				return (-1);*/
			retval = getline(&cmd, &bytes, stdin);
	/*		retval = our_getline(&cmd, &bytes, STDIN_FILENO);*/
			if (retval == -1)
			{
				free(cmd);
				exit(98);
			}
			cmd[stringlen(cmd) - 1] = '\0';
			tokens = the_tokeniser(cmd, delim);
			if (file_check(tokens, environ) == 0)
			{
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
		else
		{
			retval = getline(&cmd, &bytes, stdin);
			/*retval = our_getline(&cmd, &bytes, STDIN_FILENO);*/
			if (retval == -1)
			{
				free(cmd);
				exit(98);
			}
			cmd[stringlen(cmd) - 1] = '\0';
			tokens = the_tokeniser(cmd, delim);
			if (file_check(tokens, environ) == 0)
			{
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
				cmd_not_found_error(tokens[0]);
		}
	}
	return (0);
}
