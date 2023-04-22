#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char n, char *de)
{
	while (*de)
	{
		if (*de++ == n)
		{
			return (1);
		}
		else
		{
	              return (0);
		}
	}
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
	{
			
		return (1);
	}
			
	else
	{
		return (0);
	}
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *v)
{
	int i, si = 1, fl = 0, out;
	unsigned int r = 0;

	for (i = 0;  v[i] != '\0' && f != 2; i++)
	{
		if (v[i] == '-')
			si *= -1;

		if (v[i] >= '0' && v[i] <= '9')
		{
			fl = 1;
			r *= 10;
			r += (v[i] - '0');
		}
		else if (fl == 1)
			fl = 2;
	}

	if (si == -1)
		out = -r;
	else
		out = r;

	return (out);
}
