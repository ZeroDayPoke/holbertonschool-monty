#include "monty.h"

void swap_monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *nodeHold1, *nodeHold2;

	if (!((*stack)->next))
		errHand(7, "NA", line_number);
	nodeHold1 = (*stack);
	nodeHold2 = (*stack)->next;
	(*stack) = (*stack)->next;
	nodeHold1->next = nodeHold2->next;
	nodeHold1->prev = nodeHold2;
	nodeHold2->next = nodeHold1;
	nodeHold2->prev = NULL;
}
