#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @c: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *c)
{
	int x = 0;

	if (!c)
		return (0);

	while (*c++)
		x++;
	return (x);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @c1: the first strang
 * @c2: the second strang
 *
 * Return: negative if c1 < c2, positive if c1 > c2, zero if c1 == c2
 */
int _strcmp(char *c1, char *c2)
{
	while (*c1 && *c2)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	if (*c1 == *c2)
		return (0);
	else
		return (*c1 < *c2 ? -1 : 1);
}

/**
 * starts_with - checks if needl starts with haystack
 * @hays: string to search
 * @needl: the substring to find
 *
 * Return: address of next char of hays or NULL
 */
char *starts_with(const char *hays, const char *needl)
{
	while (*needl)
		if (*needl++ != *hays++)
			return (NULL);
	return ((char *)hays);
}

/**
 * _strcat - concatenates two strings
 * @de: the destination buffer
 * @s: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *de, char *s)
{
	char *r = de;

	while (*de)
		de++;
	while (*s)
		*dee++ = *s++;
	*de = *s;
	return (r);
}
