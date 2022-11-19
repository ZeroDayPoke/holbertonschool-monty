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
	stack_t *dasStack = NULL;
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
	theGrail = malloc(sizeof(char *) * 2);
	if (!theGrail)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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
	free_tiktok(&dasStack);
	fclose(inboundFD);
	return (0);
}
