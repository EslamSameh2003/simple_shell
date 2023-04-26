#include "shell.h"

/**
 * main - Entry point
 * @aC: arg Count
 * @aV: arg Vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int aC, char **aV)
{
	info_t info[] = { INFO_INIT };
	int f = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (f)
		: "r" (f));

	if (aC == 2)
	{
		f = open(aV[1], O_RDONLY);
		if (f == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Not open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = f;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
