#include "monty.h"

/**
 * _mod - adds the top two elements of the stack.
 * @stack: the top of the stack
 * @line_number: the line number of the opcode
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int res = 0;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exitf(stack); }
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exitf(stack); }
	res = temp->next->n % temp->n;
	temp->next->n = res;
	pop(stack, line_number); }
