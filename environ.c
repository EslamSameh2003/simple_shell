#include "shell.h"

/**
 * _myenv - Prints The Current Environment
 * @in: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: always 0
 */
int _myenv(info_t *in)
{
	print_list_str(in->env);
	return (0);
}

/**
 * _getenv - gets the Value of an Environ variable
 * @in: Structure containing potential arguments. Used to maintain
 * @na: env var Name
 *
 * Return:The Value
 */
char *_getenv(info_t *in, const char *na)
{
	list_t *temp = in->env;
	char *c;

	while (temp)
	{
		c = starts_with(temp->str, na);
		if (c && *c)
			return (c);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a New Environment variable,
 *             or modify an existing one
 * @in: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *in)
{
	if (in->argc != 3)
	{
		_eputs("incoreect number is \n");
		return (1);
	}
	if (_setenv(in, in->argv[1], in->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @in: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *in)
{
	int x;

	if (in->argc == 1)
	{
		_eputs("few arguement: \n");
		return (1);
	}
	for (x = 1; x <= in->argc; x++)
		_unsetenv(in, in->argv[x]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @in: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: always 0
 */
int populate_env_list(info_t *in)
{
	list_t *temp = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&temp, environ[x], 0);
	info->env = temp;
	return (0);
}
