#include "monty.h"

/**
 * errHand - handles errors for monty
 * @eNum: error number
 * Return: void
 */
void errHand(int eNum)
{
	char *errMsg1 = "USAGE: monty file\n";

	if (eNum == 1)
		write_error(errMsg1);
	
	exit(EXIT_FAILURE);
}
