#include "monty.h"
/**
* add - adds the top two elements of the stack
* @stack: Double pointer to the head of the stack
* @line_number: Line number of the opcode
* Return: Nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	(*stack)->next->n += (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
}
