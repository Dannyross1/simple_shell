#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (*len == 0)
	{
	free(*buf);
	*buf = NULL;
	signal(SIGINT, sigintHandler);
	r = getline(buf, &len_p, stdin);
	if (r > 0)
{
		if ((*buf)[r - 1] == '\n')
		{
			(*buf)[r - 1] = '\0';
			r--;
		}
		info->linecount_flag = 1;
		*len = r;
		info->cmd_buf = buf;
	}
	}
	return (r);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	putchar('\n');
	r = input_buf(info, &buf, &len);
	if (r == -1)
	{
		return (-1);
	}
	if (len)
	{
		j = i;
		p = buf + i;

	while (j < len)
	{
	if (buf[j] == ';')
	{
	break;
	}
	i = j + 1;
	if (i >= len)
	{
		i = len = 0;
	info->cmd_buf_type = 0;
	}
	*buf_p = p;
	return (strlen(p));
	}
	*buf_p = buf;
		return (r);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;

if (*i != 0)
{
return (0);
}
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
{
*i = r;
}
return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
static size_t i, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL
p = *ptr;
if (p && length)
{
s = *length;
}
if (i == len)
{
i = len = 0;
}

r = read_buf(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
{
return (-1);
}
char *c = strchr(buf + i, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
char *new_p = realloc(p, s ? s + k : k + 1);
if (!new_p)
{
if (p)
{
free(p);
}
return (-1);
}
if (s)
{
strncat(new_p, buf + i, k - i);
}
else
{
strncpy(new_p, buf + i, k - i + 1);
}
s += k - i;
i = k;
p = new_p;
if (length)
{
*length = s;
}
*ptr = p;
return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(int sig_num)
{
putchar('\n');
printf("$ ");
fflush(stdout);
}
int main(void)
{
info_t info;
info.readfd = 0;
info.arg = NULL;
info.cmd_buf = NULL;
info.cmd_buf_type = 0;
info.linecount_flag = 0;
info.histcount = 0;

ssize_t bytes_read = get_input(&info);
if (bytes_read == -1)
{
printf("Error reading input\n");
return (1);
}
printf("Bytes read: %zd\n", bytes_read);
printf("Input: %s\n", info.arg);

if (info.arg)
{
free(info.arg);
}
if (info.cmd_buf)
{
free(info.cmd_buf);
}
return (0);
}
