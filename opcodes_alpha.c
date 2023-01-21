#include "monty.h"

/**
 * push_monty_stack - pushes int to DLL stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	unsigned int j = 1;
	char numStr[12];
	int n;

	if (!(daedalus.op_arg[0]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	newNode = malloc(sizeof(stack_t));
	if (!((daedalus.op_arg[0] >= '0' && daedalus.op_arg[0] <= '9')
	|| daedalus.op_arg[0] == '-'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	numStr[0] = daedalus.op_arg[0];
	while (daedalus.op_arg[j])
	{
		if (isdigit(daedalus.op_arg[j]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(newNode);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		numStr[j] = daedalus.op_arg[j];
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
void pall_monty(stack_t **stack, unsigned int line_number)
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
void pint_monty(stack_t **stack, unsigned int line_number)
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
void nop_monty(stack_t **stack, unsigned int line_number)
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
void pop_monty(stack_t **stack, unsigned int line_number)
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
