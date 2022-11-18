#include "monty.h"

char **theGrail = NULL;

/**
 * main - Entry point for monty
 * Description: coming soon
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char c;
	unsigned int lineTotes = 1, i = 0, j = 0;
	FILE *inboundFD = NULL;
	char *line;

	if (argc != 2)
		errHand(1);
	inboundFD = fopen(argv[1], "r");
	while ((c = fgetc(inboundFD)) != EOF)
		if (c == '\n')
			lineTotes++;
	theGrail = malloc(sizeof(char *) * lineTotes);
	fclose(inboundFD);
	inboundFD = fopen(argv[1], "r");
	c = '0';
	line = malloc(100);
	while ((c = fgetc(inboundFD)) != EOF)
	{
		if (c == '\n')
		{
			line[j] = '\0';
			theGrail[i] = strdup(line);
			i++;
			j = 0;
		}
		else
		{
			line[j] = c;
			j++;
		}
	}
	line[j] = '\0';
	theGrail[i] = strdup(line);
	fclose(inboundFD);
	op_fun_res(lineTotes);
	free(theGrail);
	exit(EXIT_SUCCESS);
}
