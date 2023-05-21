#include "shell.h"

/**
 * printEnvironment - prints the current environment
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int printEnvironment(info_t *info)
{
	printLinkedList(info->environment);
	return (0);
}

/**
 * getEnvironmentVariable - gets the value of an environment variable
 * @info: Structure containing potential arguments
 * @name: environment variable name
 * Return: the value of the variable
 */
char *getEnvironmentVariable(info_t *info, const char *name)
{
	list_t *node = info->environment;
	char *p;

	while (node)
	{
		p = startsWith(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * setEnvironmentVariable - Initialize a new env var or modify an existing one
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int setEnvironmentVariable(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (EnvironmentVariable(info, info->args[1], info->args[2]))
		return (0);
	return (1);
}

/**
 * unsetEnvironmentVariable - Remove an environment variable
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int unsetEnvironmentVariable(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		EnvironmentVariable(info, info->args[i]);

	return (0);
}

/**
 * populateEnvironmentList - populates the environment linked list
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int populateEnvironmentList(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environment[i]; i++)
		add_node_end(&node, environment[i], 0);
	info->environment = node;
	return (0);
}
