#include "monty.h"
#define DEFAULT_LINE_SIZE 256
struct fal GV;

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
	GV.fP = fopen(argv[1], "r");
	if (GV.fP == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exitf(&top); }
	while (1)
	{
		rby = getline(&GV.line, &n, GV.fP);
		if (rby == EOF)
			break;
		if (rby == '\0' || GV.line[0] == '\n')
			continue;
		if (isallspaces(GV.line) == 1)
			continue;
		GV.line[strcspn(GV.line, "\n")] = '\0';
		lineNo++;
		instr = strtok(GV.line, "\t\n ");
		ptrop = get_op_code(instr);
		if (ptrop == NULL)
		{
			printf("L%d: unknown instruction %s\n", lineNo, instr);
			exitf(&top); }
		ptrop(&top, lineNo); }
	free_dlistint(top);
	free(GV.line);
	fclose(GV.fP);
	return (0); }
