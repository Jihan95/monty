#include "monty.h"

/**
 * isNumber - checks if passed string is number
 * @str: passed string
 *
 * Return: 0 if it is not a number, 1 otherwise
 */

int isNumber(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++; }
	return (1); }
