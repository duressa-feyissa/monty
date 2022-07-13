#include "monty.h"

/**
 * ADD - adds the top two elements of the stack
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void ADD(stack_t **obs, unsigned int count)
{
	stack_t *temp;
	int i;

	i = 0;
	temp = *obs;
	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		if (*obs == NULL)
			freeFun(obs);
		exit(EXIT_FAILURE);
	}
	temp = (*obs)->next;
	temp->n = (*obs)->n + temp->n;
	temp->prev = NULL;
	free(*obs);
	*obs = temp;
}

/**
 * NOP - doesn’t do anything
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void NOP(stack_t **obs, unsigned int count)
{
	(void)count;
	(void)obs;
}

/**
 * SUB - subtracts the top element of the stack
 * from the second top element of the stack.
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void SUB(stack_t **obs, unsigned int count)
{
	stack_t *temp;
	int i;

	i = 0;
	temp = *obs;
	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		if (*obs == NULL)
			freeFun(obs);
		exit(EXIT_FAILURE);
	}
	temp = (*obs)->next;
	temp->n = temp->n - (*obs)->n;
	temp->prev = NULL;
	free(*obs);
	*obs = temp;
}

/**
 * MUL - multiplies the second top element of the stack
 * with the top element of the stack.
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void MUL(stack_t **obs, unsigned int count)
{
	stack_t *temp;
	int i;

	i = 0;
	temp = *obs;
	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		if (*obs == NULL)
			freeFun(obs);
		exit(EXIT_FAILURE);
	}
	temp = (*obs)->next;
	temp->n = (*obs)->n * temp->n;
	temp->prev = NULL;
	free(*obs);
	*obs = temp;
}

/**
 * DIV - divides the second top element of the stack
 * by the top element of the stack.
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void DIV(stack_t **obs, unsigned int count)
{
	stack_t *temp;
	int i;

	i = 0;
	temp = *obs;
	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		if (*obs == NULL)
			freeFun(obs);
		exit(EXIT_FAILURE);
	}

	if ((*obs)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		if (*obs == NULL)
			freeFun(obs);
		exit(EXIT_FAILURE);
	}
	temp = (*obs)->next;
	temp->n = temp->n / (*obs)->n;
	temp->prev = NULL;
	free(*obs);
	*obs = temp;
}
