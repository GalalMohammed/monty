#include "monty.h"

/**
  * _getline - reads a line
  * @buf: buffer
  * @fd: file descriptor
  *
  * Return: 0 if eof, -1 if it fails, number of reads if it success
  */
int _getline(char *buf, int fd)
{
	int buf_idx = -1, read_letters;
	char c;

	do {
		buf_idx++;
		read_letters = read(fd, &c, 1);
		buf[buf_idx] = c;
	} while (buf[buf_idx] != '\n' && read_letters > 0);
	buf[buf_idx] = '\0';
	return (read_letters);
}

/**
  * op_func - perform op function
  * @cmd: instruction to be performed
  * @stack: stack to be used
  * @line_number: interpreted line number
  */
void op_func(char *cmd, stack_t **stack, unsigned int line_number)
{
	char numbuf[17];
	int i;
	instruction_t ins[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"sub", sub}, {"div", _div}, {"mul", mul},
		{"mod", mod}};

	if (cmd && strcmp(cmd, "nop") && cmd[0] != '#')
	{
		for (i = 0; i < 10; i++)
			if (!strcmp(cmd, ins[i].opcode))
			{
				ins[i].f(stack, line_number);
				break;
			}
		if (i == 10)
		{
			write(STDERR_FILENO, "L", 1);
			citoa(line_number, numbuf);
			write(STDERR_FILENO, numbuf, strlen(numbuf));
			write(STDERR_FILENO, ": unknown instruction ", 22);
			write(STDERR_FILENO, cmd, strlen(cmd));
			write(STDERR_FILENO, "\n", 1);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
}

/**
  * read_file - reads a monty file
  * @file_name: monty file name
  */
void read_file(char *file_name)
{
	char buf[1000], *tok;
	stack_t *stack = (void *)'\0';
	size_t line_number = 1;
	int fd = open(file_name, O_RDONLY), read_letters;

	if (fd < 0)
	{
		write(STDERR_FILENO, "Error: Can't open file ", 23);
		write(STDERR_FILENO, file_name, strlen(file_name));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	do {
		read_letters = _getline(buf, fd);
		tok = strtok(buf, " \t");
		op_func(tok, &stack, line_number);
		line_number++;
	} while (read_letters > 0);
	close(fd);
	free_stack(&stack);
}

/**
  * main - program entry point
  * @argc: args counter
  * @argv: array of args
  *
  * Return: ext_stat
  */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	read_file(argv[1]);
	return (EXIT_SUCCESS);
}
