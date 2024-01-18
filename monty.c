#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point
 * @arc: Argument count
 * @argv: Argument variable
 * Return: Always (0) Success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	stack = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t");

		if (opcode == NULL)
		{
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			value = atoi(strtok(NULL, " \n\t"));

			if (value == 0 && strcmp(strtok(NULL, " \n\t"), "0") != 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, value);
		} else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		} else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		} else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		} else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		} else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		} else
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	if (line)
	{
		free(line);
	}
	return (0);
}

