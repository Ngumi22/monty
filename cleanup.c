#include "monty.h"
/**
* cleanup - Cleans up resources and frees memory
* @stack: Pointer to the stack
* @file: File pointer to the opened file
* Return: Nothing
*/
void cleanup(stack_t **stack, FILE *file)
{
	fclose(file);

	while (*stack != NULL)
	{
		stack_t *temp = *stack;
		*stack = temp->next;
		free(temp);
	}
}
