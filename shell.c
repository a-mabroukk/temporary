#include "main.h"



/**
 *freeandexit - part of main
 *@buffer: internal var arg
 *@lasterr: internal var arg
 *@b_readsize: internal var arg
 *Return: nothing
 */
void freeandexit(char *buffer, int lasterr, ssize_t b_readsize)
{
	if (b_readsize == -1)
	{
		free(buffer);
		exit(lasterr);
	}
}

/**
 *mainpart1 - part of main
 *@tokens: internal var arg
 *@buffer: internal var arg
 *@c_argv: internal var arg
 *Return: nothing
 */
int mainpart1(char **tokens, char **buffer, char ***c_argv)
{
	int argcount = 0;

	*tokens = strtok(*buffer, " ");
	if (*tokens == NULL)
		return (1);
	argcount = 0;
	*c_argv = (char **) malloc(500);
	while (*tokens != NULL)
	{
		(*c_argv)[argcount] = *tokens;
		*tokens = strtok(NULL, " ");
		++argcount;
	}

	(*c_argv)[argcount] = 0;
	return (0);
}

/**
 *main_part2 - part of main
 *@was_exit: internal var arg
 *@was_env: internal var arg
 *@lasterr: internal var arg
 *@c_argv: internal var arg
 *Return: nothing
 */
int main_part2(int was_exit, int was_env, int *lasterr, char **c_argv)
{
	if (was_exit || was_env)
	{
		*lasterr = 2;
		if (was_env)
			*
			lasterr = 0;
		free(c_argv);
		return (1);
	}

	return (0);
}

/**
 *main_part3 - part of main
 *@fullpath: internal var arg
 *@argv: internal var arg
 *@argc: internal var arg
 *@c_argv: internal var arg
 *@lasterr: internal var arg
 *@buffer: internal var arg
 *@envp: internal var arg
 *Return: nothing
 */
void main_part3(char **fullpath, char **argv, int argc, char ***c_argv,
int *lasterr, char *buffer, char **envp)
{
	int r_code, status;
	pid_t child_pid = -2;

	if (*fullpath == NULL)
	{
		write_notfound_error(argv[0], argc, (*c_argv)[0]);
		*lasterr = 127;
	}
	else
	{
		(*c_argv)[0] = *fullpath;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(buffer);
			exit(1);
		}
	}
	if (child_pid == 0)
	{
		r_code = execve((*c_argv)[0], (*c_argv), envp);
		if (r_code == -1)
		{
			perror(argv[0]);
			free(buffer);
			exit(r_code);
		}

		exit(r_code);
	}
	else if (child_pid != -2)
	{
		wait(&status);
		*lasterr = status;
	}
	free(*fullpath);
	free(*c_argv);
}

/**
 *main - Write a UNIX command line interpreter
 *@argc: number of command line arguments
 *@argv: an array of character pointers listing all arguments
 *@envp: a globel variable
 *Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buffer = NULL, *tokens, **c_argv, *path, *fullpath;
	int lasterr = 0, was_exit, was_env;
	size_t b_size = 1024;
	ssize_t b_readsize = 0;

	argc = 0;
	while (1)
	{
		argc++;
		part1_main();
		b_readsize = getline(&buffer, &b_size, stdin);
		freeandexit(buffer, lasterr, b_readsize);
		remove_newline(&b_readsize, &buffer);
		if (mainpart1(&tokens, &buffer, &c_argv))
			continue;
		was_exit = handle_exit(c_argv, lasterr, argc, argv[0]);
		was_env = is_env(c_argv[0], envp);
		if (main_part2(was_exit, was_env, &lasterr, c_argv))
			continue;
		path = get_path(envp);
		if (path == NULL)
		{
			fullpath = c_argv[0];
			if (access(fullpath, X_OK) != 0 || (c_argv[0][0] != '/'))
			{
				write_notfound_error(argv[0], argc, c_argv[0]);
				lasterr = 127;
				continue;
			}
		}
		else
		{
			fullpath = get_from_path(c_argv[0], path);
		}

		main_part3(&fullpath, argv, argc, &c_argv, &lasterr, buffer, envp);
	}
	return (lasterr);
}
