#include "shell.h"

/**
 *_eputs - print an Input String
 * @st: the string to be printed
 *
 * Return: nothing
 */
void _eputs(char *st)
{
	int x = 0;

	if (!st)
		return;
	while (st[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - writes the character s to stderr
 * @s: char to print
 *
 * Return: on success 1.
 * on error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char s)
{
	static int x;
	static char bu[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, bu, x);
		i = 0;
	}
	if (s != BUF_FLUSH)
		bu[x++] = s;
	return (1);
}

/**
 * _putfd - writes the character s to given f
 * @s: The character to print
 * @f: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char s, int f)
{
	static int x;
	static char bu[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(f, bu, x);
		x = 0;
	}
	if (s != BUF_FLUSH)
		bu[x++] = s;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @st: the string to be printed
 * @f: the filedescriptor to write to
 *
 * Return: The Number of Chars  
 */
int _putsfd(char *st, int f)
{
	int x = 0;

	if (!st)
		return (0);
	while (*st)
	{
		x += _putfd(*st++, f);
	}
	return (x);
}
