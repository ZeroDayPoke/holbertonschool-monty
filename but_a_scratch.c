#include "monty.h"

/**
 * errHand - handles errors for monty
 * @eNum: error number
 * Return: void
 */
void errHand(int eNum, char *errArg, unsigned int lNum)
{
	char *errMsg1 = "USAGE: monty file\n";
	char *errMsg2 = "Error: Can't open file ";
	char *errMsg3_1 = "L";
	char *errMsg3_2 = ": unknown instruction ";
	char *nLine = "\n";
	char lNumStr[10];
	char *errMsg4 = ": usage: push integer\n";

	sprintf(lNumStr, "%d", lNum);
	if (eNum == 1)
		write_error(errMsg1);
	else if (eNum == 2)
	{
		write_error(errMsg2);
		write_error(errArg);
		write_error(nLine);
	}
	else if (eNum == 3)
	{
		write_error(errMsg3_1);
		write_error(lNumStr);
		write_error(errMsg3_2);
		write_error(errArg);
		write_error(nLine);
	}
	else if (eNum == 4)
	{
		write_error(errMsg3_1);
		write_error(lNumStr);
		write_error(errMsg4);
	}
	exit(EXIT_FAILURE);
}
