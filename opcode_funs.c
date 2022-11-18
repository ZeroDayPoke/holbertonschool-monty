#include "monty.h"

/**
 * push_monty_stack - pushes int to stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
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

/**
 * pall_monty_stack - pushes int to stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
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

/**
 * pint_monty_stack - pushes int to stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pint_monty_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		errHand2(5, line_number);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * nop_monty_stack - pushes int to stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void nop_monty_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pop_monty_stack - pushes int to stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pop_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *scrubber;

	(void)line_number;
	if (!(*stack))
	{
		errHand2(6, line_number);
	}
	scrubber = *stack;
	if (scrubber->next)
		*stack = scrubber->next;
}
