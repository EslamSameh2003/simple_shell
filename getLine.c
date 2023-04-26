#include "shell.h"

/**
 * input_buf - buffers Chained commands
 * @inf: Struct of parameter
 * @buffer: Address of buffer
 * @lenv: Address of leng var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t* inf, char** buffer, size_t* lenv)
{
	ssize_t x = 0;
	size_t len_p = 0;

	if (!*lenv) /* if there is nothing in buffer, fill it */
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		x = getline(buffer, &len_p, stdin);
#else
		x = _getline(inf, buffer, &len_p);
#endif
		if (x > 0)
		{
			if ((*buffer)[x - 1] == '\n')
			{
				(*buffer)[x - 1] = '\0'; /* remove trailing newline */
				x--;
			}
			inf->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(inf, *buffer, inf->histcount++);
			
			{
				*lenv = x;
				inf->cmd_buf = buffer;
			}
		}
	}
	return (x);
}

/**
 * get_input - gets a line minus of the newline
 * @inf: struct of parameter
 *
 * Return: bytes read
 */
ssize_t get_input(info_t* inf)
{
	static char* buffer; /* the ';' command chain buffer */
	static size_t y, z, len;
	ssize_t x = 0;
	char** buf_poin = &(inf->arg), * poin;

	_putchar(BUF_FLUSH);
	x = input_buf(inf, &buffer, &len);
	if (x == -1) /* End of File. */
		return (-1);
	if (len)	/* a Commands remain in the chain buffer */
	{
		z = y; /* Init new Iterator to current buffer posi */
		poin = buffer + y; /* Get the pointer to return it */

		check_chain(inf, buffer, &z, y, len);
		while (z < len) /*Checking the chain  */
		{
			if (is_chain(inf, buffer, &z))
				break;
			z++;
		}

		y = z + 1; /* increment  ';'' */
		if (y >= len) /* reached end of buffer? */
		{
			y = len = 0; /*  posi and length = 0 */
			inf->cmd_buf_type = CMD_NORM;
		}

		*buf_poin = poin; /* pass back pointer to the current buffer poin position */
		return (_strlen(poin)); /* return the leng of current command */
	}

	*buf_poin = buffer; /* get back buffer from _getline() */
	return (x); /* return leng of buffer  */
}

/**
 * read_buf - reads a buffer
 * @inf: parameter struct
 * @buffer: buffer
 * @y: size
 *
 * Return: x
 */
ssize_t read_buf(info_t* inf, char* buf, size_t* y)
{
	ssize_t x = 0;

	if (*y)
		return (0);
	x = read(inf->readfd, buf, READ_BUF_SIZE);
	if (x >= 0)
		*y = x;
	return (x);
}

/**
 * _getline - gets the next line of input from STDIN
 * @inf: struct of parameter
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @leng: size of preallocated ptr buffer
 *
 * Return: L_poin
 */
int _getline(info_t* inf, char** ptr, size_t* leng)
{
	static char buffer[READ_BUF_SIZE];
	static size_t y, len;
	size_t z;
	ssize_t x = 0, L_poin = 0;
	char* poin = NULL, * new_poin = NULL, * c;

	poin = *ptr;
	if (poin && leng)
		L_poin = *leng;
	if (y == len)
		y = len = 0;

	x = read_buf(inf, buffer, &len);
	if (x == -1 || (x == 0 && len == 0))
		return (-1);

	c = _strchr(buffer + y, '\n');
	z = c ? 1 + (unsigned int)(c - buffer) : len;
	new_poin = _realloc(poin, L_poin, L_poin ? L_poin + z : z + 1);
	if (!new_poin) /* MALLOC FAILURE! */
		return (poin ? free(poin), -1 : -1);

	if (L_poin)
		_strncat(new_poin, buffer + y, z - y);
	else
		_strncpy(new_poin, buffer + y, z - y + 1);

	L_poin += z - y;
	y = z;
	poin = new_poin;

	if (leng)
		*leng = L_poin;
	*ptr = poin;
	return (L_poin);
}

/**
 * sigintHandler - prevent ctrl-C
 * @signal_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int signal_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
