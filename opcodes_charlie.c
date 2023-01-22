#include "monty.h"

/**
 * mod_monty - mods top 2 nodes of stack
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void mod_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmpNode = (*stack);
	tmpNode->next->n %= tmpNode->n;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmpNode);
}
