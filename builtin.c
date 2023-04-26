#include "shell.h"

/**
 * _myexit - get out of shell
 * @inf: Structure containing arguments
 *  Return: 
 *         
 */
int _myexit(info_t* inf)
{
	int ExitCheck;

	if (inf->argv[1])  /* If there is an Exit */
	{
		ExitCheck = _erratoi(inf->argv[1]);
		if (ExitCheck == -1)
		{
			inf->status = 2;
			print_error(inf, "change the number: ");
			_eputs(inf->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inf->err_num = _erratoi(inf->argv[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory
 * @inf: Structure containing Arguments.
 *  Return: 0
 */
int _mycd(info_t* inf)
{
	char* x, * directory, buffer[1024];
	int chdirec_ret;

	x = getcwd(buffer, 1024);
	if (!x)
		_puts(" error message<<\n");
	if (!inf->argv[1])
	{
		directory = _getenv(inf, "HOME=");
		if (!directory)
			chdirec_ret = chdir((directory = _getenv(inf, "PWD=")) ? directory : "/");
		else
			chdirec_ret = chdir(directory);
	}
	else if (_strcmp(inf->argv[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
		chdirec_ret = chdir((directory = _getenv(inf, "OLDPWD=")) ? directory : "/");
	}
	else
		chdirec_ret = chdir(inf->argv[1]);
	if (chdirec_ret == -1)
	{
		print_error(inf, "can't cd  ");
		_eputs(inf->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(inf, "oldpwd", _getenv(inf, "pwd="));
		_setenv(inf, "pwd", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory
 * @inf: Structure containingarguments
 *  Return: 0
 */
int _myhelp(info_t* inf)
{
	char** argum_array;

	argum_array = inf->argv;
	_puts(" Function not Implemented yet \n");
	if (0)(
		_puts(*argum_array); )
		return (0);
}

