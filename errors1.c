#include "shell.h"

/**
 * _erratoi - this helps converts a string to an integer
 * @s: this is the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 *  Auth: Adesuwa and Daniel
 */
int _erratoi(char *s)
{
unsigned long int result = 0;

if (*s == '+')
s++;

for (; *s != '\0'; s++)
{
if (*s >= '0' && *s <= '9')
{
result = result * 10 + (*s - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}

return ((int)result);
}

/**
 * print_error - this helps to print an error message
 * @info: this is the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->args[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * print_d - this is the function prints a decimal (integer) number (base 10)
 * @input: the input function
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
int count = 0;
int (*putchar_func)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
unsigned int _abs_, current;

if (input < 0)
{
_abs_ = -input;
putchar_func('-');
count++;
}
else
{
_abs_ = input;
}

current = _abs_;

for (int i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
putchar_func('0' + current / i);
count++;
}
current %= i;
}

putchar_func('0' + current);
count++;

return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;
char *array =
(flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}

ptr = &buffer[49];
*ptr = '\0';

do

{
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;

return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
for (int i = 0; buf[i] != '\0'; i++)
{
if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
}
/**
 * main - entry point
 *
 * Return: nothing
 */
int main(void)
{
return (0);
}
