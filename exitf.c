#include "monty.h"
FILE *fP;

/**
 * exitf - freeing the stack and exit the program
 * @stack: the head of the list
 */

void exitf(stack_t **stack)
{
	if (*stack != NULL)
		free_dlistint(*stack);
	fclose(fP);
	exit(EXIT_FAILURE);
}
