#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second = first->next;

	first->prev = second;
	first->next = second->next;

	second->prev = NULL;
	second->next = first;

	*stack = second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (second->next != NULL)
	{
		second->next->prev = first;
	}
}
