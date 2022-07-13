#include "monty.h"
#include<ctype.h>
/**
 * MOD - computes the rest of the division of the
 * second top element of the stack
 * by the top element of the stack.
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void MOD(stack_t **obs, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
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
	temp->n = temp->n % (*obs)->n;
	temp->prev = NULL;
	free(*obs);
	*obs = temp;
}

/**
 * _PCHAR - prints the char at the top of the stack,
 * followed by a new line.
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void _PCHAR(stack_t **obs, unsigned int count)
{
	int n;

	if (*obs == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	n = (*obs)->n;
	if (n >= 0 || n < 128)
		printf("%c\n", n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		exit(EXIT_FAILURE);
	}
}

/**
 * _PSTR - prints the string starting at the top of the stack,
 * followed by a new line.
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void _PSTR(stack_t **obs, unsigned int count)
{
	stack_t *str;

        if (*obs == NULL)
        {
                fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
                exit(EXIT_FAILURE);
        }

	(void)count;
	str = *obs;
	while (str)
	{
		if (str->n >= 0 || str->n < 256)
		{
			if (str->n != 0)
				printf("%c", str->n);
			else
				break;
		}
		else
		{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
                exit(EXIT_FAILURE);
		}
		str = str->next;
	}
	printf("\n");
}

/**
 * ROT1 - rotates the stack to the top.
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void ROT1(stack_t **obs, unsigned int count)
{
	int temp;
	stack_t *head;

	if (*obs == NULL)
		return;
	(void)count;
	head = *obs;
	temp = head->n;
	while (head && head->next)
	{
		head->n = (head->next)->n;
		head = head->next;
	}
	head->n = temp;
}

/**
 * ROTR - rotates the stack to the bottom.
 * @obs: monty data
 * @count: line of command on file
 *
 * Return: Void
 */
void ROTR(stack_t **obs, unsigned int count)
{
	stack_t *head, *ptr;

	if (*obs == NULL)
		return;
	(void)count;
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ptr->n = 0;
	ptr->prev = NULL;
	ptr->next = NULL;
	head = *obs;
	while (head && head->next)
		head = head->next;
	ptr->n = head->n;
	free(head);
	head = *obs;
	head->prev = ptr;
	ptr->next = head;
	*obs = ptr;
}
