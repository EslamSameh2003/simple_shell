#include "shell.h"

/**
 * _myhistory - displays the history list
 * @inf: Struct contain potential arguments
 *  Return: 0
 */
int _myhistory(info_t* inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @inf: struct of parameter 
 * @st: the alias of string 
 * Return: return 0 on success else return 1 
 */
int unset_alias(info_t* inf, char* st)
{
	char* poin, z;
	int retur;

	poin = _strchr(st, '=');
	if (!poin)
		return (1);
	z = *poin;
	*poin = 0;
	retur = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, st, -1)));
	*poin = z;
	return (retur);
}

/**
 * set_alias - sets alias to string
 * @inf: parameter struct
 * @st: the alia of stri
 *
 * Return: Always 0 on success else return 1 
 */
int set_alias(info_t* inf, char* st)
{
	char* poin;

	poin = _strchr(st, '=');
	if (!poin)
		return (1);
	if (!*++poin)
		return (unset_alias(inf, st));

	unset_alias(inf, st);
	return (add_node_end(&(inf->alias), st, 0) == NULL);
}

/**
 * print_alias - prints an alia stri
 * @node: the alia nod
 *
 * Return: Always 0 on success else return 1
 */
int print_alias(list_t* node)
{
	char* poin = NULL, * n = NULL;

	if (node)
	{
		poin = _strchr(node->str, '=');
		for (n = node->str; n <= poin; n++)
			_putchar(*n);
		_putchar('\'');
		_puts(poin + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias function 
 * @inf: Struct contain potential arguments.
 *  Return:  0
 */
int _myalias(info_t* inf)
{
	int x = 0;
	char* poin = NULL;
	list_t* node = NULL;

	if (inf->argc == 1)
	{
		node = inf->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; inf->argv[x]; x++)
	{
		poin = _strchr(inf->argv[x], '=');
		if (poin)
			set_alias(inf, inf->argv[x]);
		else
			print_alias(node_starts_with(inf->alias, inf->argv[x], '='));
	}

	return (0);
}
