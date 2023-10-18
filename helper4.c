#include "main.h"

/**
 *_strdub - a function that duplicates string
 *@src: a string to be duplicated
 *Return: value
 */
char *_strdub(const char *src)
{
	char *dest;
	int i = 0, n = 0;

	while (src[n] != '\0')
		n++;
	dest = (char *) malloc(n + 1);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[n] = '\0';
	return (dest);
}

/**
 *get_full_path - a function that will combine arguments to generate a
 *full path to the ending path
 *@start: a pointer to string containing the starting path
 *@end: a pointer to string containing the ending path
 *Return: value
 */
char *get_full_path(const char *start, const char *end)
{
	int start_length = 0, end_length = 0, i;
	char *result;

	while (start[start_length] != '\0')
	{
		start_length++;
	}

	while (end[end_length] != '\0')
	{
		end_length++;
	}

	result = (char *) malloc(start_length + end_length + 2);

	for (i = 0; i < start_length; i++)
	{
		result[i] = start[i];
	}

	result[start_length] = '/';
	for (i = 0; i < end_length; i++)
	{
		result[start_length + 1 + i] = end[i];
	}

	result[start_length + 1 + end_length] = '\0';
	return (result);
}

/**
 *get_from_path - searcehes for the command in the given path
 *@command: a pointer to string that containing command to serch for
 *@path: the path to search in
 *Return: the full path
 */
char *get_from_path(char *command, const char *path)
{
	char *token, *full_path;
	char *path_clone;

	if (command[0] == '/' || command[0] == '.')
	{
		full_path = _strdub(command);
		return (full_path);
	}

	path_clone = _strdub(path);
	token = strtok(path_clone, ":");
	while (token != NULL)
	{
		full_path = get_full_path(token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_clone);
			return (full_path);
		}

		token = strtok(NULL, ":");
		free(full_path);
	}

	free(path_clone);
	return (NULL);
}

/**
 *is_env - a function that checks if the given variable name is environment va
 *@c: a pointer to a string containing the varaible name to check
 *@envp: pointer to array of pointers to environment varaibles
 *Return: 1
 */
int is_env(char *c, char **envp)
{
	int len = 0;
	char **env;

	while (c[len] != '\0')
		len++;
	if (len == 3)
	{
		if (c[0] == 'e' && c[1] == 'n' && c[2] == 'v')
		{
			for (env = envp; *env != NULL; env++)
			{
				write(1, *env, _strlen(*env));
				write(1, "\n", 1);
			}

			return (1);
		}
	}

	return (0);
}
