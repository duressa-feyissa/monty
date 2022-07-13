#include "monty.h"

/**
 * freeFun - frees memory
 * @obs: monty data
 *
 * Return: Void
 */
void freeFun(stack_t **obs)
{
	stack_t *current;

	current = *obs;
	while (current)
	{
		current = current->next;
		free(*obs);
		*obs = current;
	}
}
