#include "monty.h"
/**
 * push - Pushes a new node with a specified value to the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @value: Value to be pushed onto the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */
void monty_push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
