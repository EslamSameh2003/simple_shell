#include "shell.h"

/**
 **_strncpy - copies a string
 *@de:  destination string to be copied to
 *@sr:  source string
 *@x:  amount of characters to be copied
 *Return:  concatenated string
 */
char *_strncpy(char *de, char *sr, int x)
{
	int N, v;
	char *c = de;

	N = 0;
	while (sr[N] != '\0' && x < x - 1)
	{
		de[N] = sr[N];
		 N++;
	}
	if (N < x)
	{
		v = N;
		while (v < x)
		{
			de[v] = '\0';
			v++;
		}
	}
	return (c);
}

/**
 **_strncat - concatenates two strings
 *@de:  first string
 *@s:  second string
 *@x:  amount of bytes to be maximally used
 *Return:  concatenated string
 */
char *_strncat(char *de, char *sr, int x)
{
	int g, m;
	char *c = de;

	g = 0;
	m = 0;
	while (de[g] != '\0')
		g++;
	while (sr[m] != '\0' && m < n)
	{
		de[g] = src[m];
		g++;
		m++;
	}
	if (m < x)
		de[g] = '\0';
	return (c);
}

/**
 **_strchr - locates a character in a string
 *@c1:  string to be parsed
 *@c2:  character to look for
 *Return: (c1) a pointer to the memory area c1
 */
char *_strchr(char *c1, char c2)
{
	do {
		if (*c1 == c2)
			return (c1);
	} while (*c1++ != '\0');

	return (NULL);
}
