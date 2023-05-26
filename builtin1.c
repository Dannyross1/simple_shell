#include "shell.h"

/**
 * displayHistory - displays the history list, one command by line,
 * preceded with line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int displayHistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unsetAlias - removes an alias from the alias list
 * @info: parameter struct
 * @alias: the alias to unset
 * Return: Always 0 on success, 1 on error
 */
int unsetAlias(info_t *info, char *alias)
{
	char *equalSignPos, savedChar;
	int result;

	equalSignPos = _strchr(alias, '=');
	if (!equalSignPos)
		return (1);

	savedChar = *equalSignPos;
	*equalSignPos = '\0';

	result = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, alias, -1)));

	*equalSignPos = savedChar;
	return (result);
}

/**
 * setAlias - sets an alias to a string
 * @info: parameter struct
 * @alias: the alias to set
 * Return: Always 0 on success, 1 on error
 */
int setAlias(info_t *info, char *alias)
{
	char *equalSignPos;

	equalSignPos = _strchr(alias, '=');
	if (!equalSignPos)
		return (1);

	if (!*++equalSignPos)
		return (unsetAlias(info, alias));

	unsetAlias(info, alias);
	return (add_node_end(&(info->alias), alias, 0) == NULL);
}

/**
 * printAlias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int printAlias(list_t *node)
{
	char *equalSignPos = NULL, *aliasString = NULL;

	if (node)
	{
		equalSignPos = _strchr(node->str, '=');
		for (aliasString = node->str; aliasString <= equalSignPos; aliasString++)
			_putchar(*aliasString);
		_putchar('\'');
		_puts(equalSignPos + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * manageAlias - manages the alias functionality
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int manageAlias(info_t *info)
{
	int i = 0;
	char *equalSignPos = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printAlias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->args[i]; i++)
	{
		equalSignPos = _strchr(info->args[i], '=');
		if (equalSignPos)
			setAlias(info, info->args[i]);
		else
			printAlias(node_starts_with(info->alias, info->args[i], '='));
	}

	return (0);
}
