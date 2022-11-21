#include "monty.h"

/**
 * free_tiktok - free DLL type stack and globals
 * @stack: DLL type stack head
 * Return: void
 */
void free_tiktok(stack_t **stack)
{
	stack_t *scrubber;

	if (theGrail)
	{
		free(theGrail[0]);
		free(theGrail);
	}
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
