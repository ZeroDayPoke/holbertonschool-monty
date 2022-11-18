#include "monty.h"

void op_fun_res(unsigned int lineCount)
{
	stack_t *dasStack;
	unsigned int i = 0, j, targetFound;
	instruction_t betty[] = {{"pall", pall_monty_stack}, {"push", push_monty_stack}};

	dasStack = NULL;
	for (i = 0; i < lineCount; i++)
	{
		targetFound = 0;
		for (j = 0; j < 2; j++)
		{
			if (strncmp(betty[j].opcode, theGrail[i], 4) == 0)
			{
				betty[j].f(&dasStack, (i + 1));
				targetFound = 1;
			}
		}
		if (theGrail[i][0] == '#' || theGrail[i][0] == '\0')
			targetFound = 1;
		if (targetFound == 0)
			errHand(3, theGrail[i], (i + 1));
	}
}

void push_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	unsigned int j = 1;
	char *rawStr;
	char numStr[12];
	int n;

	newNode = malloc(sizeof(stack_t));
	rawStr = theGrail[line_number - 1];
	rawStr += 4;
	if (!((rawStr[0] >= '0' && rawStr[0] <= '9') || rawStr[0] == '-'))
		errHand(4, "NA", line_number);
	numStr[0] = rawStr[0];
	while (rawStr[j] >= '0' && rawStr[j] <= '9')
	{
		numStr[j] = rawStr[j];
		j++;
	}
	numStr[j] = '\0';
	n = atoi(numStr);
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = newNode;
	*stack = newNode;
}

void pall_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nodePtr;

	nodePtr = (*stack);
	while (nodePtr)
	{
		printf("%d\n", nodePtr->n);
		nodePtr = nodePtr->next;
	}
	(void)line_number;
}
