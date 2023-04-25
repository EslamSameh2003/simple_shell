#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @c: the string to be converted
 * Return: 0 if no numbers in string,
 *     converted number otherwise
 *       -1 on error
 */
int _erratoi(char *c)
{
	int x = 0;
	unsigned long int res = 0;

	if (*c == '+')
		c++;  /* TODO: why does this make main return 255? */
	for (x = 0;  c[x] != '\0'; x++)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			res *= 10;
			res += (c[x] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error - prints an error message
 * @in: the parameter & return in struct
 * @es: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *in, char *es)
{
	_eputs(in->fname);
	_eputs(": ");
	print_d(in->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(in->argv[0]);
	_eputs(": ");
	_eputs(es);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @inp: the input
 * @f: the filedescriptor to write 
 *
 * Return: number of characters printed
 */
int print_d(int inp, int f)
{
	int (*__putchar)(char) = _putchar;
	int x, co = 0;
	unsigned int _abs_, curr;

	if (f == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_abs_ = -inp;
		__putchar('-');
		co++;
	}
	else
		_abs_ = input;
	curr = _abs_;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (_abs_ / x)
		{
			__putchar('0' + curr / x);
			co++;
		}
		curr %= x;
	}
	__putchar('0' + curr);
	co++;

	return (co);
}

/**
 * convert_number - converter function, a clone of itoa
 * @nu: Number
 * @ba: Base
 * @flag:flags of arguement
 *
 * Return: string
 */
char *convert_number(long int nu, int ba, int flag)
{
	static char *arr;
	static char buff[50];
	char si = 0;
	char *pt;
	unsigned long x = num;

	if (!(flag & CONVERT_UNSIGNED) && nu < 0)
	{
		x = -nu;
		si = '-';

	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buff[49];
	*pt = '\0';

	do	{
		*--pt = arr[x % ba];
		n /= base;
	} while (n != 0);

	if (sign)
		*--pt = si;
	return (pt);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @bu: modify address string
 *
 * Return: always 0;
 */
void remove_comments(char *bu)
{
	int x;

	for (x = 0; bu[x] != '\0'; x++)
		if (bu[x] == '#' && (!x || bu[x - 1] == ' '))
		{
			bu[x] = '\0';
			break;
		}
}
