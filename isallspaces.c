#include "monty.h"

/**
 * isallspaces - check if all lines is spaces
 * @str: the line
 *
 * Return: 1 in case of spaces, 0 otherwise
 */

int isallspaces(const char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))
			return (0);
		str++; }
	return (1); }
