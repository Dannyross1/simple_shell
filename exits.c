#include "shell.h"

/**
 * my_strncpy - this function copies a string
 * @destination: this is the destination string to be copied to
 * @source: this is the source string
 * @num: this represents the number of characters to be copied
 * Return: this returns the concatenated string
 */
char *my_strncpy(char *destination, char *source, int num)
{
	int i;
	char *result = destination;

	i = 0;
	while (source[i] != '\0' && i < num - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < num)
	{
		int j = i;

		while (j < num)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (result);
}

/**
 * my_strncat - this function concatenates or join two strings
 * @destination: this is the first string
 * @source: this is the second string
 * @num: this represents the number of bytes to be maximally used
 * Return: this returns the concatenated string
 */
char *my_strncat(char *destination, char *source, int num)
{
	int i, j;
	char *result = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0' && j < num)
	{
		destination[i] = source[j];
		i++;
		j++;
	}
	if (j < num)
		destination[i] = '\0';
	return (result);
}

/**
 * my_strchr - this is used to locate a character in a string
 * @str: this is the string to be parsed
 * @c: this is the character to look for in the code
 * Return: this returns a pointer to the memory area str
 */
char *my_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
