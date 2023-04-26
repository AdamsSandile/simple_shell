#include "main.h"

/**
 * error_env - error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *error_env(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1] != NULL && _strcmp(datash->args[1], "-") == 0)
		msg = ": Invalid option -\n";
	else if (datash->args[1] == NULL)
		msg = ": No variable name specified\n";
	else if (_getenv(datash->env, datash->args[1]) == NULL)
		msg = ": Undefined variable\n";
	else
		msg = ": Unable to modify environment variable\n";
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * error_path_126 - error message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *error_path_126(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;
	char *msg;

	ver_str = aux_itoa(datash->counter);
	msg = ": Permission denied, ";
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 12;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	if (access(datash->args[0], F_OK) != 0)
	{
		_strcat(error, ": No such file or directory\n");
	}
	else if (access(datash->args[0], X_OK) != 0)
	{
		_strcat(error, msg);
		_strcat(error, "permission denied\n");
	}
	else
	{
		_strcat(error, ": Error executing command\n");
	}
	free(ver_str);
	return (error);
}

