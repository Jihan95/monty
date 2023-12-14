#include "monty.h"
#define DEFAULT_LINE_SIZE 256
char *line = NULL;
FILE *fP;

/**
 * main - the main logic of program
 * @argc: the number of command line arguments
 * @argv: the command line vector
 *
 * Return: 0 in case of success
 */

int main(int argc, char *argv[])
{
	int lineNo = 0;
	char *instr;
	size_t n = DEFAULT_LINE_SIZE;
	ssize_t rby;
	void (*ptrop)(stack_t **, unsigned int);
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exitf(&top); }
	fP = fopen(argv[1], "r");
	if (fP == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exitf(&top); }
	while (1)
	{
		rby = getline(&line, &n, fP);
		if (rby == EOF)
			break;
		if (rby == '\0' || line[0] == '\n')
			continue;
		line[strcspn(line, "\n")] = '\0';
		lineNo++;
		instr = strtok(line, "\t\n ");
		instr[strcspn(instr, "\n")] = '\0';
		ptrop = get_op_code(instr);
		if (ptrop == NULL)
		{
			printf("L%d: unknown instruction %s\n", lineNo, instr);
			exitf(&top); }
		ptrop(&top, lineNo); }
	free_dlistint(top);
	free(line);
	fclose(fP);
	return (0); }
