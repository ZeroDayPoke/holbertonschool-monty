#include "monty.h"

/**
 * main - Entry point for monty
 * Description: coming soon
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char c;
	unsigned int lineTotes = 1, i = 0, j = 0, chrCnt = 1;
	FILE *inboundFD = NULL;
	char **theGrail;
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
	while (c != -1)
	{
		line = malloc(100);
		for (chrCnt = 1, j = 0; c != '\n'; chrCnt++, j++)
		{
			c = fgetc(inboundFD);
			line[j] = c;
		}
		theGrail[i] = strdup(line);
		printf("%s\n", theGrail[i]);
		free(line);
		i++;
	}
	return (0);
}
