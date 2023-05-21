#include "shell.h"

/**
 * _eputs - this helps prints an input string
 * @str: this is the string to be printed
 *
 * Return: Nothing
 * Auth: Daniel and Adesuwa
 */
void _eputs(char *str)
{
if (str == NULL)
return;

while (*str != '\0')
{
_eputchar(*str);
str++;
}
}

/**
 * _eputchar - writes the character c to standard error
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
static char buf[WRITE_BUF_SIZE];
static int bufIndex;

if (c == BUF_FLUSH || bufIndex >= WRITE_BUF_SIZE - 1)
{
write(2, buf, bufIndex);
bufIndex = 0;
}

if (c != BUF_FLUSH)
{
buf[bufIndex] = c;
bufIndex++;
}

return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
static char buf[WRITE_BUF_SIZE];
static int bufIndex;

if (c == BUF_FLUSH || bufIndex >= WRITE_BUF_SIZE - 1)
{
write(fd, buf, bufIndex);
bufIndex = 0;
}

if (c != BUF_FLUSH)
{
buf[bufIndex] = c;
bufIndex++;
}

return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
int count = 0;

if (str == NULL)
return (0);

while (*str != '\0')
{
count += _putfd(*str, fd);
str++;
}

return (count);
}

/**
 * main - entry point
 *
 * Return: noting
 */
int main(void)
{
	return (0);
}
