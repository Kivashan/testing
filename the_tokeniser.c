#include "main.h"

char **the_tokeniser(char *cmd, char *delim)
{
	char **tokens;
	char *tmp;
	int args = 0, len = 0, i = 0;

	if (!cmd)
		return (NULL);

	args = no_of_args(cmd, delim);
	tokens = malloc(sizeof(char *) * (args + 1)); /* +1 for null*/
	
	if (!tokens)
		return (NULL);

	for (i = 0; i < args; i++)
	{
		len = 0;
		tmp = strtok(cmd, delim);
		len = stringlen(tmp);
		tokens[i] = malloc(sizeof(char) * (len + 1));
		if (!tokens[i])
			return (NULL);
	}
	tokens[i] = NULL;
	return (tokens);
}
