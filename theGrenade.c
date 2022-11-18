#include "monty.h"

/**
 * op_fun_res - do things
 * @lineCount: the linecount
 * Return: void
 */
void op_fun_res(unsigned int lineCount)
{
	stack_t *dasStack;
	unsigned int i = 0, j, targetFound;
	instruction_t betty[] = {{"pall", pall_monty_stack},
	{"push", push_monty_stack}, {"pint", pint_monty_stack},
	{"nop", nop_monty_stack}, {"pop", pop_monty_stack},
	{"swap", swap_monty_stack}, {"add", add_monty_stack}};

	dasStack = NULL;
	for (i = 0; i < lineCount; i++)
	{
		targetFound = 0;
		for (j = 0; j < 7; j++)
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
