#include "monty.h"

/**
 * swap_monty_stack - pushes int to stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void swap_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold1, *nodeHold2;

	if (!((*stack)->next))
		errHand2(7, line_number);
	nodeHold1 = (*stack);
	nodeHold2 = (*stack)->next;
	(*stack) = (*stack)->next;
	nodeHold1->next = nodeHold2->next;
	nodeHold1->prev = nodeHold2;
	nodeHold2->next = nodeHold1;
	nodeHold2->prev = NULL;
}

/**
 * add_monty_stack - pushes int to stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void add_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold1;
	int n;

	if (!((*stack)->next))
		errHand2(8, line_number);
	nodeHold1 = (*stack);
	n = (((*stack)->n) + ((*stack)->next->n));
	nodeHold1->n = n;
	nodeHold1->prev = NULL;
	nodeHold1->next = (*stack)->next->next;
	*stack = nodeHold1;
}
