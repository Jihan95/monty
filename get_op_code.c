#include "monty.h"

/**
 * get_op_code - mapping between instruction and the function
 * @ins: the passed instruction
 *
 * Return: a pointer to the corresponding function
 */
void (*get_op_code(char *ins))(stack_t **, unsigned int)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(ins, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
