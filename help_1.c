#include "main.h"

/**

help_env - Help information for the built-in env command

Return: no return.
*/
void help_env(void)
{
char *help = "env: env [option] [name=value] [command [args]]\n\t";

write(STDOUT_FILENO, help, _strlen(help));
help = "Print the environment of the shell.\n";
write(STDOUT_FILENO, help, _strlen(help));
help = "\tIf no command is given, the environment is printed.\n";
write(STDOUT_FILENO, help, _strlen(help));
help = "\tIf a command is given, it is executed with arguments and the environment.\n";
write(STDOUT_FILENO, help, _strlen(help));
help = "\tOptions:\n";
write(STDOUT_FILENO, help, _strlen(help));
help = "\t-h: Display this help message and exit.\n";
write(STDOUT_FILENO, help, _strlen(help));
help = "\t-0: Output null bytes instead of newlines.\n";
write(STDOUT_FILENO, help, _strlen(help));
help = "\t-u: Unset the specified environment variable.\n";
write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * help_setenv - Help information for the builtin setenv
 * Return: no return
 */
void help_setenv(void)
{

	char *help = "setenv: setenv (const char *name, const char *value, int replace)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));

	help = "Add a new definition to the environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));

	help = "name: name of the new variable.\n";
	write(STDOUT_FILENO, help, _strlen(help));

	help = "value: value to assign to the new variable.\n";
	write(STDOUT_FILENO, help, _strlen(help));

	help = "replace: flag to indicate whether to replace an existing variable.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * help_unsetenv - Help information for the builtin unsetenv
 * Return: no return
 */
void help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * help_general - Help information for the general shell
 * Return: no return
 */
void help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined internally. Type 'help' to see the list.\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "  alias: alias [name=['string']]\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "  cd: cd [-L|[-P [-e]] [-@]] [dir]\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "  exit: exit [n]\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "  env: env [option] [name=value] [command [args]]\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "  setenv: setenv [variable] [value]\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "  unsetenv: unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * help_exit - Help information fot the builint exit
 * Return: no return
 */
void help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "status of the last command executed\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
