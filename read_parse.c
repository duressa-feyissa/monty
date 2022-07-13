#include "monty.h"

/**
 * readFun - read from file
 * @filename: name of the file
 * @obs: monty data
 *
 * Return: Void
 */
void readFun(char *filename, stack_t **obs)
{
	FILE *file;
	char buf[128];
	unsigned int count = 0;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(buf, sizeof(buf), file))
	{
		count++;
		parse(buf, obs, count);
	}
}

/**
 * parse - organize data read from file
 * @str: command read from file
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void parse(char *str, stack_t **obs, unsigned int count)
{
	char *hold, *data;
	(void)obs;
	(void)count;
	if (str[0] == '\n')
		str = "nop";
	hold = strtok(str, "\t\r\n ");
	if (strcmp(hold, "push") == 0)
	{
		data = strtok(NULL, " $\n");
		glob.num = data;
	}
	hold = analysis(hold);
	findCommad(obs, hold, count);
}


/**
 * findCommad - find function which perfom different commands
 * @str: command read from file
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void findCommad(stack_t **obs, char *str, unsigned int count)
{
	unsigned int i;
	instruction_t op[] = {
		{"push", PUSH},
		{"pint", _PINT},
		{"pall", PALL},
		{"pop", POP},
		{"swap", SWAP},
		{"add", ADD},
		{"nop", NOP},
		{"sub", SUB},
		{"mul", MUL},
		{"div", DIV},
		{"mod", MOD},
		{"pchar", _PCHAR},
		{"pstr", _PSTR},
		{"rotl", ROT1},
		{"rotr", ROTR},
		{NULL, NULL}

	};

	i = 0;
	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(obs, count);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", count, str);
	exit(EXIT_FAILURE);
}

/**
 * checkString - check whether the string is integer value
 * @str: string
 *
 * Return: On succes return 1 Otherwise 0
 */
int checkString(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (isdigit(str[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	glob.value = atoi(str);
	return (1);
}
