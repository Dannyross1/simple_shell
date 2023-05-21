#include "shell.h"

/**
 * get_str_array_length - this is use to calculate the length of the array
 *
 * Return: 0 always 
 */
size_t get_str_array_length(char **arr)
{
    size_t length = 0;
    if (arr) {
        while (arr[length] != NULL)
            length++;
    }
    return length;
}

/**
 * clear_info - this is used to initialize info_t struct
 * @info: this is struct address
 */
void clear_info(info_t *info)
{
memset(info, 0, sizeof(info_t));
}

/**
 * set_info - this is used to initialize info_t struct
 * @info: this is struct address
 * @av: this is an argument vector used in the code
 */
void set_info(info_t *info, char **av)
{
info->fname = av[0];
if (info->arg)
{
info->argv = strtow(info->arg, " \t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}
info->argc = info->argv ? get_str_array_length(info->argv) : 0;

replace_alias(info);
replace_vars(info);
}
}

/**
 * free_info - this frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
ffree(info->argv);
info->argv = NULL;
info->path = NULL;
if (all)
{
if (!info->cmd_buf)
free(info->arg);
free_list(&(info->env));
free_list(&(info->history));
free_list(&(info->alias));
ffree(info->environment);
info->environment = NULL;
bfree((void **)info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
_putchar(BUF_FLUSH);
}
}
