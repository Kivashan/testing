#include "main.h"

/**
 * cmd_not_found_error - prints error message on stdout
 * @token: the command entered on the cmdline
 *
 * Return: Void
 */

void cmd_not_found_error(char *token)
{
	_puts("bash: ");
	_puts(token);
	_puts(": command not found\n");
}
