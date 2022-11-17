#include "monty.h"

/**
 * write_to_SO - function that writes a char to SO
 * @c: character to be written
 * Return: 1 on successful stdout write
 */
int write_to_SO(char c)
{
	return (write(1, &c, 1));
}

/**
 * write_to_SE - function that writes a char to SE
 * @c: character to be written
 * Return: 1 on successful stderr write
 */
int write_to_SE(char c)
{
	return (write(2, &c, 1));
}

/**
 * write_error - writes string error to SE
 * @str: string to be written
 * Return: void
 */
void write_error(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		write_to_SE(*(str + i));
	}
}
