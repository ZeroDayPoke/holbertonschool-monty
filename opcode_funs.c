#include "monty.h"

/**
 * push_monty_stack - pushes int to DLL stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void push_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	unsigned int j = 1;
	char numStr[12];
	int n;

	if (!(theGrail[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_tiktok(stack);
		exit(EXIT_FAILURE);
	}
	newNode = malloc(sizeof(stack_t));
	if (!((theGrail[1][0] >= '0' && theGrail[1][0] <= '9')
	|| theGrail[1][0] == '-'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_tiktok(stack);
		exit(EXIT_FAILURE);
	}
	numStr[0] = theGrail[1][0];
	while (theGrail[1][j])
	{
		if (isdigit(theGrail[1][j]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(newNode);
			free_tiktok(stack);
			exit(EXIT_FAILURE);
		}
		numStr[j] = theGrail[1][j];
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
 * pall_monty_stack - prints DLL type stack to SO
 * @stack: DLL type stack
 * @line_number: line number from inbound file
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
	(void) line_number;
}

/**
 * pint_monty_stack - prints top int of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void pint_monty_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * nop_monty_stack - does nothing to stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void nop_monty_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pop_monty_stack - removes top int node of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void pop_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		nodeHold = (*stack)->next;
		free((*stack));
		(*stack) = nodeHold;
	}
}
