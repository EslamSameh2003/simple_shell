#include "shell.h"

/**
 * _strcpy - copies a string
 * @de: The Destination
 * @s: The Source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *de, char *s)
{
	int i = 0;

	if (de == s || s == 0)
		return (de);
	while (s[i])
	{
		de[i] = s[i];
		i++;
	}
	de[i] = 0;
	return (de);
}

/**
 * _strdup - Duplicates a String
 * @st: the string to duplicate
 *
 * Return: Pointer  The Duplicated String
 */
char *_strdup(const char *st)
{
	int len = 0;
	char *re;

	if (st == NULL)
		return (NULL);
	while (*st++)
		len++;
	re = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		re[len] = *--st;
	return (re);
}

/**
 *_puts - prints an input string
 *@st: the string to be printed
 *
 * Return: nothing
 */
void _puts(char *st)
{
	int x = 0;

	if (!st)
		return;
	while (st[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @s: The character to print
 *
 * Return: On successed 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char s)
{
	static int x;
	static char bu[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, bu, x);
		x = 0;
	}
	if (s != BUF_FLUSH)
		bu[x++] = s;
	return (1);
}
