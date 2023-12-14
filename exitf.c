#include "monty.h"

/**
 * exitf - freeing the stack and exit the program
 * @stack: the head of the list
 */

void exitf(stack_t **stack)
{
	if (*stack != NULL)
		free_dlistint(*stack);
	free(GV.line);
	fclose(GV.fP);
	exit(EXIT_FAILURE);
}
