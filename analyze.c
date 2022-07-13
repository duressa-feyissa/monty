#include "monty.h"

/**
 * analysis - handle comment and if the command is
 * either stack or queue
 * @str: command
 *
 * Return: String
 */
char *analysis(char *str)
{
	if (strcmp(str, "\n") == 0)
		return ("nop");
	else if (str[0] == '#')
		return ("nop");
	else if (strcmp(str, "stack") == 0)
	{
		glob.change = 0;
		return ("nop");
	}
	else if (strcmp(str, "queue") == 0)
	{
		glob.change = 1;
		return ("nop");
	}
	return (str);
}

/**
 * firstError - diplay error if number of argument is wrong
 * Return: Void
 */
void firstError(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

/**
 * secondError - diplay error if the file can't open
 * @s: name of the file
 * Return: Void
 */
void secondError(char *s)
{
	fprintf(stderr, "Error: Can't open file %s\n", s);
}

/**
 * thirdError - diplay error if the instruction was unkwon
 * @s: command
 * @i: line of command on file
 *
 * Return: Void
 */
void thirdError(unsigned int i, char *s)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", i, s);
	exit(EXIT_FAILURE);
}
