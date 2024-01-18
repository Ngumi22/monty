#include "monty.h"

/**
* exec - Executes the corresponding operation based on opcode
* @stack: Pointer to the stack
* @opcode: Opcode to execute
* @line_number: Line number in the file
* @file: File pointer to the opened file
*/
void exec(stack_t **stack, char *opcode, unsigned int line_number, FILE *file)
{
	int value;

	if (strcmp(opcode, "push") == 0)
	{
		value = atoi(strtok(NULL, " \t\n"));

		if (value == 0 && strcmp(strtok(NULL, " \t\n"), "0") != 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			cleanup(stack, file);
			exit(EXIT_FAILURE);
		}
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
        {
                nop(stack, line_number);
        }
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		cleanup(stack, file);
		exit(EXIT_FAILURE);
	}
}
