#include "main.h"

/**
 * strcat_cd - concatenates error message for cd command
 *
 * @datash: shell data
 * @msg: error message to print
 * @error: output error message buffer
 * @ver_str: version string
 *
 * Return: pointer to error message buffer
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
    if (!datash || !msg || !error || !ver_str)
        return NULL;

    // Concatenate error message parts
    strcpy_s(error, BUFFER_SIZE, datash->av[0]);
    strcat_s(error, BUFFER_SIZE, ": ");
    strcat_s(error, BUFFER_SIZE, ver_str);
    strcat_s(error, BUFFER_SIZE, ": ");
    strcat_s(error, BUFFER_SIZE, datash->args[0]);
    strcat_s(error, BUFFER_SIZE, msg);

    // Add illegal flag to error message
    if (datash->args[1][0] == '-')
    {
        char illegal_flag[2];
        illegal_flag[0] = '-';
        illegal_flag[1] = datash->args[1][1];
        strcat_s(error, BUFFER_SIZE, illegal_flag);
    }
    else
    {
        strcat_s(error, BUFFER_SIZE, datash->args[1]);
    }

    strcat_s(error, BUFFER_SIZE, "\n");
    return error;
}

/**
 * generate_error_cd - generates an error message for the cd command
 *
 * @datash: pointer to data relevant to the command
 *
 * Return: pointer to the generated error message
 */
char *generate_error_cd(data_shell *datash)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = int_to_str(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": invalid option -- '";
		len_id = 1;
	}
	else
	{
		msg = ": no such file or directory: ";
		len_id = str_len(datash->args[1]);
	}

	length = str_len(datash->av[0]) + str_len(datash->args[0]);
	length += str_len(ver_str) + str_len(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == NULL)
	{
		free(ver_str);
		return (NULL);
	}

	error = concatenate_error_message(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * concatenate_error_message - concatenates the different parts of the error message
 *
 * @datash: pointer to data relevant to the command
 * @msg: pointer to the message to print
 * @error: pointer to the output message
 * @ver_str: pointer to the counter lines
 *
 * Return: pointer to the concatenated error message
 */
char *concatenate_error_message(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	str_copy(error, datash->av[0]);
	str_cat(error, ": ");
	str_cat(error, ver_str);
	str_cat(error, ": ");
	str_cat(error, datash->args[0]);
	str_cat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		str_cat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		str_cat(error, datash->args[1]);
	}

	str_cat(error, "\n");
	str_cat(error, "\0");
	return (error);
}

/**
 * error_not_found - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(data_shell *datash)
{
    int length;
    char *error;
    char *ver_str;

    ver_str = aux_itoa(datash->counter);
    length = _strlen(datash->av[0]) + _strlen(ver_str);
    length += _strlen(datash->args[0]) + 20;
    error = malloc(sizeof(char) * (length + 1));
    if (error == NULL)
    {
        free(ver_str);
        return NULL;
    }

    _strcpy(error, datash->av[0]);
    _strcat(error, ": ");
    _strcat(error, ver_str);
    _strcat(error, ": ");
    _strcat(error, datash->args[0]);

    // Check if the command is not installed on the system
    if (access(datash->args[0], F_OK) == -1)
    {
        _strcat(error, ": command not found");
    }
    else
    {
        _strcat(error, ": command not found or misspelled");
    }

    _strcat(error, "\n");
    _strcat(error, "\0");

    free(ver_str);
    return error;
}

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 29;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": ");
	if (!isdigit(datash->args[1][0]) && datash->args[1][0] != '-')
	{
		_strcat(error, "command not found: ");
		_strcat(error, datash->args[1]);
		_strcat(error, "\n");
	}
	else if (datash->args[1][0] == '-')
	{
		_strcat(error, "Illegal option: ");
		_strcat(error, datash->args[1]);
		_strcat(error, "\n");
	}
	else
	{
		_strcat(error, "numeric argument required: ");
		_strcat(error, datash->args[1]);
		_strcat(error, "\n");
	}
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

