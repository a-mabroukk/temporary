#include "main.h"

/**
 *_strcmp - compares two strings
 *
 *@s1: first string to be compare
 *
 *@s2: second string to be compare
 *
 *Description: Write a function that compares two strings
 *
 *Return: result
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 *inttoa - a function that convert integer to string
 *
 *@val: an integer number to be converted
 *
 *Return: value
 */
char *inttoa(int val)
{
	static char buf[32] = { 0 };

	int i = 30;

	for (; val && i; --i, val /= 10)

		buf[i] = "0123456789abcdef"[val % 10];

	return (&buf[i + 1]);

}

/**
 *_strlen - a function that returns the length of a string
 *
 *@s: a string whose lenght is to be printed
 *
 *Description: Write a function that returns the length of a string
 *
 *Return: Length
 */

int _strlen(char *s)
{
	int L;

	for (L = 0; *s != '\0'; s++)
		++L;

	return (L);
}

/**
 *part1_main - part of main
 *Return: nothing
 */
void part1_main(void)
{
	int inter = 0;

	inter = isatty(fileno(stdin));
	if (inter)
		write(1, PROMPT, 2);
}

/**
 *is_digit - checks for a digit
 *
 *@s: the number to be checked
 *
 *Description: Write a function that checks for a digit (0 through 9)
 *
 *Return: 1 if c is a digit, 0 otherwise
 */

int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}
