#include "monty.h"

void op_fun_res(char **theGrail, unsigned int lineCount)
{
	stack_t **dasStack;
	unsigned int i, j;
	instruction_t betty[] = {{"pall", pall_monty_stack}, {"push", push_monty_stack}};

	dasStack = malloc(lineCount * sizeof(stack_t));
	for (i = 0; theGrail[i]; i++)
	{
		dasStack[i] = malloc(sizeof(stack_t));
		for (j = 0; j < 2; j++)
		{
			if (strncmp(betty[j].opcode, theGrail[i], 4) == 0)
			{
				betty[j].f(dasStack, lineCount);
			}
		}
	}
}

void push_monty_stack(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	if (!(stack) || !(line_number))
		exit(EXIT_FAILURE);
	stack[i]->n = 4;
	stack[i]->next = NULL;
	stack[i]->prev = NULL;
}

void pall_monty_stack(stack_t **stack, unsigned int line_number)
{
	if (!(stack) || !(line_number))
		exit(EXIT_FAILURE);
}
