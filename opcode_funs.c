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
		if (targetFound == 0)
			errHand(3, theGrail[i], (i + 1));
	}
}

void push_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	unsigned int j = 0;
	char *rawStr, *numStr;
	int n, i;

	/* alloc mem for newNode and check for oopsy */
	newNode = malloc(sizeof(stack_t));
	numStr = malloc(12);
	/* fill newNode struct members */
	rawStr = theGrail[line_number - 1];
	for (i = 0; rawStr[i]; i++)
	{
		if ((rawStr[i] >= '0' && rawStr[i] <= '9') || rawStr[i] == '-')
		{
			numStr[j] = rawStr[j + i];
			j++;
			while (rawStr[i + j] >= '0' && rawStr[i + j] <= '9')
			{
				numStr[j] = rawStr[j + i];
				j++;
			}
			break;
		}
	}
	numStr[j + 1] = '\0';
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
