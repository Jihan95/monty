#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of the opcode
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *input = strtok(NULL, " ");
	int num;

	num = atoi(input);
	if (num == 0 && strcmp(input, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exitf(stack); }
	(*stack) = add_dnodeint(stack, num); }

/**
 * pall - prints all the values on the stack.
 * @stack: the head of the stack
 * @line_number: the line number of the opcode
 */

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	print_dlistint(*stack); }

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of the opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exitf(stack); }
	fprintf(stdout, "%d\n",  (*stack)->n); }

/**
 * pop - removes the top element of the stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of the opcode
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exitf(stack); }
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp); }

/**
 * swap - swaps the top two elements of the stack.
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of the opcode
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exitf(stack); }
	temp = (*stack);
	(*stack) = (*stack)->next;
	temp->prev = (*stack);
	temp->next = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->next = temp;
	if (temp->next != NULL)
		temp->next->prev = temp; }
