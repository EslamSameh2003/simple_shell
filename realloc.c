#include "shell.h"

/**
 **_memset - its a for loop fill the memory with constant bytes
 *@poin: the pointer to the memory address
 *@byte: the byte to fill *poin with
 *@amount: the amount of bytes to be filled
 *Return: (poin) pointer to the memory area poin
 */
char* _memset(char* p, char byte, unsigned int amount)
{
	unsigned int j;

	for (j = 0; j < amount; j++)
		p[j] = byte;
	return (p);
}

/**
 * ffree - set s string free
 * @ss: string of strings
 */
void ffree(char **ss)
{
	char **s = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(s);
}

/**
 * _realloc - reallocate s block of memory
 * @pt: pointer to previous mallocated block
 * @oSize:  size of bytes in old block
 * @nSize:  size of bytes in new block
 *
 * Return: (poin)the pointer to the memory address.
 */
void *_realloc(void* pt, unsigned int oSize, unsigned int nSize)
{
	char *poin;

	if (!pt)
		return (malloc(nSize));
	if (!nSize)
		return (free(pt), NULL);
	if (nSize == oSize)
		return (pt);

	poin = malloc(nSize);
	if (!poin)
		return (NULL);

	oSize = oSize < nSize ? oSize : nSize;
	while (oSize--)
		poin[oSize] = ((char*)pt)[oSize];
	free(pt);
	return (poin);
}
