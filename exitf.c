#include "monty.h"

/**
 * exitf - freeing the stack and exit the program
 * @stack: the head of the list
 */

void exitf(stack_t **stack)
{
	if (*stack != NULL)
		free_dlistint(*stack);
	free(line);
	fclose(fP);
	exit(EXIT_FAILURE);
}
