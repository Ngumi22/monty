#include "monty.h"
#include <stdlib.h>
/**
 * pop - removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	*stack = temp->next;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
