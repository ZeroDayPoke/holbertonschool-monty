#include "monty.h"

void op_fun_res(unsigned int lineCount)
{
	stack_t **dasStack;
	unsigned int i, j;
	instruction_t betty[] = {{"pall", pall_monty_stack}, {"push", push_monty_stack}};

	dasStack = malloc(lineCount * sizeof(stack_t));
	for (i = 0; theGrail[i]; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (strncmp(betty[j].opcode, theGrail[i], 4) == 0)
			{
				betty[j].f(dasStack, (i + 1));
			}
		}
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
		if (rawStr[i] >= '0' && rawStr[i] <= '9')
		{
			numStr[j] = rawStr[i];
		}
	}
	numStr[j + 1] = '\0';
	n = atoi(numStr);
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *stack;
	/* put at beginning of dll */
	if (*stack)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}

void pall_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nodePtr;

	if (!(stack) || !(line_number))
		exit(EXIT_FAILURE);

	/* prints node int, adds to node count, then targets next node */
	nodePtr = *stack;
	while (nodePtr)
	{
		printf("%d\n", nodePtr->n);
		nodePtr = nodePtr->next;
	}
}
