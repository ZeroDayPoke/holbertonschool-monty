#include "monty.h"

/**
 * errHand - handles errors for monty
 * @errnum: err num
 * @errarg: err arg
 * @lnum: line num
 * Return: void
 */
void errHand(int errnum, char *errarg, unsigned int lnum)
{
	char *errMsg1 = "USAGE: monty file\n";
	char *errMsg2 = "Error: Can't open file ";
	char *errMsg3_1 = "L";
	char *errMsg3_2 = ": unknown instruction ";
	char *nLine = "\n";
	char lNumStr[10];
	char *errMsg4 = ": usage: push integer\n";

	sprintf(lNumStr, "%d", lnum);
	if (errnum == 1)
		write_error(errMsg1);
	else if (errnum == 2)
	{
		write_error(errMsg2);
		write_error(errarg);
		write_error(nLine);
	}
	else if (errnum == 3)
	{
		write_error(errMsg3_1);
		write_error(lNumStr);
		write_error(errMsg3_2);
		write_error(errarg);
		write_error(nLine);
	}
	else if (errnum == 4)
	{
		write_error(errMsg3_1);
		write_error(lNumStr);
		write_error(errMsg4);
	}
	exit(EXIT_FAILURE);
}

/**
 * errHand2 - error handling
 * @errnum: err num
 * @lnum: line num
 * Return: void
 */
void errHand2(int errnum, unsigned int lnum)
{
	char *errMsg3_1 = "L";
	char *errMsg5 = ": can't pint, stack empty\n";
	char *errMsg6 = ": can't pop an empty stack\n";
	char *errMsg7 = ": can't swap, stack too short\n";
	char *errMsg8 = ": can't add, stack too short\n";
	char lNumStr[10];

	sprintf(lNumStr, "%d", lnum);
	if (errnum == 5)
	{
		write_error(errMsg3_1);
		write_error(lNumStr);
		write_error(errMsg5);
	}
	else if (errnum == 6)
	{
		write_error(errMsg3_1);
		write_error(lNumStr);
		write_error(errMsg6);
	}
	else if (errnum == 7)
	{
		write_error(errMsg3_1);
		write_error(lNumStr);
		write_error(errMsg7);
	}
	else if (errnum == 8)
	{
		write_error(errMsg3_1);
		write_error(lNumStr);
		write_error(errMsg8);
	}
	exit(EXIT_FAILURE);
}
