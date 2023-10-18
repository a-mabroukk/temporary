#include "main.h"

/**
 *_atoi - a function that convert string to integer
 *@s: a string to be converted
 *Return: 0
 */
int _atoi(char *s)
{
	int i, sign, n, len, f, digit;

	i = sign = n = f = len = digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++sign;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (sign % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}

		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}

/**
 *_puts - prints a string
 *
 *@str: string to be print
 *
 *Description: Write a function that prints a string
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str + 0);
		str++;
	}

	_putchar('\n');
}

/**
 *_putchar - writes the character c to stdout
 *@c: The character to print
 *
 *Return: On success 1.
 *On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_strcpy - copies the string
 *
 *@dest: a string in which to store the value
 *
 *@src: a string to be copy
 *
 *Description: Write a function that copies the string
 *
 *Return: value
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';
	return (dest);
}

/**
 *_strcat - concatenates two strings
 *
 *@dest: a string in which to store the value
 *
 *@src: a string to be append
 *
 *Description: Write a function that concatenates two strings
 *
 *Return: result
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{;
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	return (dest);
}
