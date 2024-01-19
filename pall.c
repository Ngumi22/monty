#include "monty.h"
/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	current = *stack;

	if (current == NULL)
	{
		return;
	}

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
