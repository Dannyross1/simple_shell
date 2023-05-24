#include "shell.h"

/**
 * exitShell - this exit the shell
 * @info: this is the structure containing potential arguments
 * print_error:  used to print
 * _eput: a function to print a string to the error output stream.
 * _eputchar: a function to print a string to the error output stream.
 * Return: this exits with a given exit status
 * (0) if info->argv[0] != "exit"
 */
int exitShell(info_t *info)
{
	int exitStatus;

	if (info->argv[1])
	{
		exitStatus = atoi(info->argv[1]);
		if (exitStatus == 0 && info->argv[1][0] != '0')
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->errorNumber = atoi(info->argv[1]);
		return (-2);
	}
	info->errorNumber = -1;
	return (-2);
}

/**
 * changeDirectory - this changes the current directory of the process
 * @info: this is the structure containing potential arguments
 * _getenv: used to retrieve the value of an environment
 * _strcmp: compares two strings and return an interger value
 * _puts: used to print a string to the standard output.
 * _putchar: used to output a single character to the standard output.
 * print_error:  used to print
 * _eputs: a function to print a string to the error output stream.
 * _eputchar: to print a string to the error output stream.
 * Setevn: used update the value of an environment variable.
 * Return: Always 0
 */
int changeDirectory(info_t *info)
{
	char *currentDir, *dir, buffer[1024];
	int chdirRet;

	currentDir = getcwd(buffer, 1024);
	if (!currentDir)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->args[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdirRet = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdirRet = chdir(dir);
	}
	else if (_strcmp(info->args[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(currentDir);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		chdirRet = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdirRet = chdir(info->args[1]);
	if (chdirRet == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->args[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * showHelp - displays help information
 * @info: Structure containing potential arguments
 * @_puts: used to print a string to the standard output.
 * Return: Always 0
 */
int showHelp(info_t *info)
{
	char **argArray;

	argArray = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argArray);
	return (0);
}
