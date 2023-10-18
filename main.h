#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROMPT "$ "

int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *inttoa(int val);
int is_digit(char *s);
int _atoi(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void remove_newline(ssize_t *b_size, char **buffer);
void write_error_message_exit(char  *argv, int loopcount, char *wrong_n);
int handle_exit(char **child_argv, int lasterr, int lc, char *p_name);
char *get_path(char *envp[]);
void write_notfound_error(char *argv, int loopcount, char *commd);
char *get_full_path(const char *start, const char *end);
char *get_from_path(char *command, const char *path);
int is_env(char *c, char **envp);
void freeandexit(char *buffer, int lasterr, ssize_t b_readsize);
int mainpart1(char **tokens, char **buffer, char ***c_argv);
int main_part2(int was_exit, int was_env, int *lasterr, char **c_argv);
void main_part3(char **fullpath, char **argv, int argc, char ***c_argv,
int *lasterr, char *buffer, char **envp);
void part1_main(void);

#endif
