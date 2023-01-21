#include "monty.h"

/**
 * free_stack - free DLL type stack
 * @stack: DLL type stack head
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *scrubber;

	if (*stack)
	{
		while (*stack)
		{
			scrubber = (*stack)->next;
			free(*stack);
			(*stack) = scrubber;
		}
	}
}
