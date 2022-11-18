#include "monty.h"

/**
 * errHand - handles errors for monty
 * @eNum: error number
 * Return: void
 */
void errHand(int eNum, char *errArg)
{
	char *errMsg1 = "USAGE: monty file\n";
	char *errMsg2 = "Error: Can't open file ";
	char *nLine = "\n";

	if (eNum == 1)
		write_error(errMsg1);
	else if (eNum == 2)
	{
		write_error(errMsg2);
		write_error(errArg);
		write_error(nLine);
	}
	exit(EXIT_FAILURE);
}
