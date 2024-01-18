int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	char line[256];
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		if (line[0] == '\n' || line[0] == '#')
		{
			continue;
		}
		char opcode[256];
		int value;

		if (sscanf(line, "%s %d", opcode, &value) == 2)
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(&stack, value, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack, line_number);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				pop(&stack, line_number);
			}
			else if (strcmp(opcode, "swap") == 0)
			{
				swap(&stack, line_number);
			} else
			{
				fprintf(stderr, "L%d: Unknown opcode %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "L%d: Invalid instruction format\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
