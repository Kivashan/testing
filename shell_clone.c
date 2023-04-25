#include "main.h"

int main(__attribute__((unused))int argc, __attribute__((unused))char *argv[],__attribute__((unused))char *env[])
{
	size_t bytes;

	while (1)
	{
		char *buffer = NULL, *delim = " ", *getline_cp;
		int mode = 0, args = 0, retval = 0;
		char **tokens = NULL;

		mode = isatty(STDIN_FILENO);
		if (mode)
			retval = get_prompt();

		retval = getline(&buffer, &bytes, stdin);
		if (retval == -1)
			getline_error_handler(buffer);
		buffer[_strlen(buffer) - 1] = '\0';	
		
		getline_cp = _strdup(buffer);
		args = no_of_args(buffer, delim);
		tokens = word_split(getline_cp, delim);
		retval = file_check(tokens);
		if (retval == 0)
			printf("File found: %s\n", tokens[0]);
		else
			printf("File not found: %s\n", tokens[0]);

		free(buffer);
		free_grid(tokens, args);
		free(getline_cp);
	}
	return(0);
}
