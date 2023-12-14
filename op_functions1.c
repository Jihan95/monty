#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: the top of the stack
 * @line_number: the line number of the opcode
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum = 0;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exitf(stack); }
	temp = (*stack);
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	pop(stack, line_number); }

/**
 * nop - doesn’t do anything
 * @stack: the head of the list
 * @line_number: the line number of the opcode
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number; }

/**
 * sub - adds the top two elements of the stack.
 * @stack: the top of the stack
 * @line_number: the line number of the opcode
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int diff = 0;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exitf(stack); }
	diff = temp->next->n - temp->n;
	temp->next->n = diff;
	pop(stack, line_number); }

/**
 * _div - dividess the top two elements of the stack.
 * @stack: the top of the stack
 * @line_number: the line number of the opcode
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int div = 0;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exitf(stack); }
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exitf(stack); }
	div = temp->next->n / temp->n;
	temp->next->n = div;
	pop(stack, line_number); }
