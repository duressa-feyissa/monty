#include "monty.h"

/**
 * PUSH - Pushes an element to the stack or queue
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void PUSH(stack_t **obs, unsigned int count)
{
	stack_t *newNode, *temp;
	int value;

	if (strcmp(glob.num, "0") != 0)
	{
		value = atoi(glob.num);
		if (value == 0 && glob.x == -1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else
		value = 0;
	newNode = malloc(sizeof(newNode));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (*obs == NULL)
	{
		*obs = newNode;
		return;
	}
	if (glob.change == 0)
		newNode->next = *obs, (*obs)->prev = newNode, *obs = newNode;
	else
	{
		temp = *obs;
		while (temp->next)
			temp = temp->next;
		temp->next = newNode, newNode->prev = temp;
	}
}

/**
 * PALL - prints all the values on the stack or queue
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void PALL(stack_t **obs, unsigned int count)
{
	stack_t *temp;

	(void)count;
	temp = *obs;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _PINT - pint prints the value at the top of the stack
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void _PINT(stack_t **obs, unsigned int count)
{
	if (*obs == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*obs)->n);
}

/**
 * POP - removes the top element of the stack or queue
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void POP(stack_t **obs, unsigned int count)
{
	stack_t *temp;

	if (*obs == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}

	temp = (*obs)->next;
	free(*obs);
	*obs = temp;
	if (*obs != NULL)
		(*obs)->prev = NULL;
}

/**
 * SWAP - swaps the top two elements of the stack
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void SWAP(stack_t **obs, unsigned int count)
{
	stack_t *temp;
	int i, swap;

	i = 0;
	temp = *obs;
	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		if (*obs == NULL)
			freeFun(obs);
		exit(EXIT_FAILURE);
	}
	temp = *obs;
	swap = temp->n;
	temp->n = (temp->next)->n;
	(temp->next)->n = swap;
}
