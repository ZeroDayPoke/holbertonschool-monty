#include "monty.h"

/**
 * swap_monty - swaps top two nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void swap_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	nodeHold = (*stack)->next;
	(*stack)->next = nodeHold->next;
	(*stack)->prev = nodeHold;
	nodeHold->next = (*stack);
	nodeHold->prev = NULL;
	(*stack) = nodeHold;
}

/**
 * add_monty - adds top 2 nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void add_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	nodeHold = (*stack);
	nodeHold->next->n = (((*stack)->n) + ((*stack)->next->n));
	(*stack) = nodeHold->next;
	free(nodeHold);
}

/**
 * sub_monty - subtracts top 2 nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void sub_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmpNode = (*stack);
	tmpNode->next->n -= tmpNode->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmpNode);
}
