#include "shell.h"

/**
 * isInteractive - this help check if the shell in in interactive mode.
 * @info: this is the  information struct
 * Return: 1 if in interactive mode, 0 otherwise
 */
int isInteractive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * isDelimiter - This help check if a character is a delimiter
 * @c: this is the character to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */
int isDelimiter(char c, char *delim)
{
while (*delim)
{
if (*delim++ == c)
return (1);
}
return (0);
}
/**
 * isAlphabetic - this helps check if a character is alphabetic
 * @c: This is the  character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int isAlphabetic(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
/**
 * convertToInteger - this helps convert a string to an integer value
 * @s: this is the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int convertToInteger(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
	flag = 1;
	result *= 10;
	result += (s[i] - '0');
}
else if (flag == 1)
	flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
