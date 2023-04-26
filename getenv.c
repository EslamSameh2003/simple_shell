#include "shell.h"

/**
 * get_environ - returns a copy of the env string array 
 * @inf: Struct contain potential arguments. 
 * Return:  0
 */
char** get_environ(info_t* inf)
{
	if (!inf->environ || inf->env_changed)
	{
		inf->environ = list_to_strings(inf->env);
		inf->env_changed = 0;
	}

	return (inf->environ);
}

/**
 * _unsetenv - Remove  env variables
 * @inf:Struct contain potential arguments. 
 *  Return: on delete return 1 else return 0
 * @vari: the string environment variable 
 */
int _unsetenv(info_t* inf, char* vari)
{
	list_t* node = inf->env;
	size_t x = 0;
	char* poin;

	if (!node || !vari)
		return (0);

	while (node)
	{
		poin = starts_with(node->str, vari);
		if (poin && *poin == '=')
		{
			inf->env_changed = delete_node_at_index(&(inf->env), x);
			x = 0;
			node = inf->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (inf->env_changed);
}

/**
 * _setenv - Initialize a new env var, or modify a one
 * @inf: Struct contain potential arguments.
 * @vari: the string environment variable property
 * @val: the string environment variable  value
 *  Return: 0
 */
int _setenv(info_t* inf, char* vari, char* val)
{
	char* buffer = NULL;
	list_t* node;
	char* poin;

	if (!vari || !val)
		return (0);

	buffer = malloc(_strlen(vari) + _strlen(val) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, vari);
	_strcat(buffer, "=");
	_strcat(buffer, val);
	node = inf->env;
	while (node)
	{
		poin = starts_with(node->str, vari);
		if (poin && *poin == '=')
		{
			free(node->str);
			node->str = buffer;
			inf->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(inf->env), buffer, 0);
	free(buffer);
	inf->env_changed = 1;
	return (0);
}
