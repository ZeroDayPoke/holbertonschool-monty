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

/**
 * pchar_monty - prints ASCII char of top node
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void pchar_monty(stack_t **stack, unsigned int line_number)
{
	char pchar;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	pchar = (*stack)->n;
	printf("%c\n", pchar);
}

/**
 * pstr_monty - prints nodes as str
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void pstr_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode;

	tmpNode = (*stack);
	while (tmpNode && tmpNode->n > 0 && tmpNode->n < 128)
	{
		printf("%c", tmpNode->n);
		tmpNode = tmpNode->next;
	}
	printf("\n");
	(void) line_number;
}

/**
 * rotl_monty - PLACEHOLDER
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void rotl_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode, *topNode, *botNode;

	botNode = (*stack);
	topNode = (*stack)->next;
	tmpNode = (*stack);
	if (!(tmpNode))
		return;
	if (!(tmpNode->next))
		return;
	while (tmpNode->next)
		tmpNode = tmpNode->next;
	tmpNode->next = botNode;
	topNode->prev = NULL;
	(*stack) = topNode;
	botNode->prev = tmpNode;
	botNode->next = NULL;
	(void) line_number;
}

/**
 * rotr_monty - PLACEHOLDER
 * @stack: DLL type stack
 * @line_number: line number from inbound file
 * Return: void
 */
void rotr_monty(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
