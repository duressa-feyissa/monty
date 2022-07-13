#include "monty.h"

global_t glob;
/**
 * main - Entry
 * @argc: number of argument
 * @argv: arguments
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char *argv[])
{
	stack_t *obs;

	obs = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	readFun(argv[1], &obs);
	freeFun(&obs);
	return (EXIT_SUCCESS);
}
