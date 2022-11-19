#include "monty.h"

char **theGrail;

/**
 * main - Entry point for monty
 * @argc: arg count
 * @argv: array of arg pointers
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	stack_t *dasStack, *scrubber;
	unsigned int lineNum = 0;
	FILE *inboundFD = NULL;
	size_t n = 0;
	char *line, *pokeyTokey, *tokeyTwo;
	const char delims[] = " \t\n";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inboundFD = fopen(argv[1], "r");
	if (!(inboundFD))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	dasStack = NULL;
	theGrail = malloc(sizeof(char *) * 2);
	while (getline(&line, &n, inboundFD) != -1)
	{
		lineNum++;
		pokeyTokey = strtok(line, delims);
		if (!pokeyTokey || pokeyTokey[0] == '#')
			continue;
		tokeyTwo = strtok(NULL, delims);
		theGrail[0] = pokeyTokey;
		theGrail[1] = tokeyTwo;
		op_fun_res(lineNum, pokeyTokey, &dasStack);
	}
	fclose(inboundFD);
	free(theGrail);
	while (dasStack)
	{
		scrubber = dasStack->next;
		free(dasStack);
		dasStack = scrubber;
	}
	return (0);
}
