#include "main.h"

/**
 *remove_newline - function that remove new line
 *@buffer: a pointer to string from whilch the new line should be removed
 *@b_size: the size of string
 */
void remove_newline(ssize_t *b_size, char **buffer)
{
	if (*(*buffer + *b_size - 1) == '\n')
	{
		*(*buffer + *b_size - 1) = '\0';
		--b_size;
	}
}

/**
 *write_error_message_exit - a built-in function that print an error message
 *when process failed
 *@argv: apointer to a string containing the name of program
 *@loopcount: a number of times the command has been searched for
 *@wrong_n: a pointer to a string containing illegal number
 */
void write_error_message_exit(char *argv, int loopcount, char *wrong_n)
{
	write(2, argv, _strlen(argv));
	write(2, ": ", _strlen(": "));
	write(2, inttoa(loopcount), _strlen(inttoa(loopcount)));
	write(2, ": exit: Illegal number: ", 24);
	write(2, wrong_n, _strlen(wrong_n));
	write(2, "\n", 1);
}

/**
 *handle_exit - a built-in function that initialize eixiting when  failed
 *@child_argv: a pointer to array of pointers to the command line arguments
 *@lasterr: the last error code that occurred
 *@p_name: a pointer to the name of program
 *@lc: loop counter
 *Return: value
 */
int handle_exit(char **child_argv, int lasterr, int lc, char *p_name)
{
	char *c = child_argv[0];
	int len = 0;

	while (c[len] != '\0')
		len++;
	if (len == 4)
	{
		if (c[0] == 'e' && c[1] == 'x' && c[2] == 'i' && c[3] == 't')
		{
			if (!child_argv[1])
			{
				free(c);
				free(child_argv);
				if (lasterr == 0)
					exit(lasterr);
				else
					exit(2);
			}
			else
			{
				if (is_digit(child_argv[1]))
				{
					lasterr = _atoi(child_argv[1]);
					free(c);
					free(child_argv);
					exit(lasterr);
				}
				else
				{
					write_error_message_exit(p_name, lc, child_argv[1]);
					return (1);
				}
			}
		}
	}

	return (0);
}

/**
 *get_path - a function that print path
 *@envp: the global variable
 *Return: value
 */
char *get_path(char *envp[])
{
	char *path = NULL;
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T' &&
			envp[i][3] == 'H' && envp[i][4] == '=')
		{
			path = envp[i] + 5;
			break;
		}
	}

	return (path);
}

/**
 *write_notfound_error - function that print no found error
 *@argv: apointer to a string containing the name of program
 *@loopcount: a number of times the command has been searched for
 *@commd: a pointer to a string containing the command that was not found
 */
void write_notfound_error(char *argv, int loopcount, char *commd)
{
	write(2, argv, _strlen(argv));
	write(2, ": ", _strlen(": "));
	write(2, inttoa(loopcount), _strlen(inttoa(loopcount)));
	write(2, ": ", _strlen(": "));
	write(2, commd, _strlen(commd));
	write(2, ": not found\n", 12);
}
