#include "monty.h"

#define MAX_LINE_LENGTH 1024
/**
* main - Entry point
* @argc: Argument count
* @argv: Argument variable
* Return: Always (0) Success
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL)
		{
			continue;
		}
		exec(&stack, opcode, line_number, file);
	}
	cleanup(&stack, file);
	return (0);
}
