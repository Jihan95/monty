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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exitf(stack); }
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exitf(stack); }
	res = temp->next->n % temp->n;
	temp->next->n = res;
	pop(stack, line_number); }

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: the top of the stack
 * @line_number: the line number of the opcode
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (dlistint_len(*stack) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exitf(stack); }
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exitf(stack); }
	fprintf(stdout, "%c\n", (char)temp->n); }
