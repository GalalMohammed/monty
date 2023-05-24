#include "monty.h"

/**
  * pall - prints all values on stack, starting from top of stack
  * @stack: stack to be printed
  * @line_number: interpreted line number
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	(void) line_number;

	while (pointer)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->next;
	}
}

/**
  * pint - prints value of the top
  * @stack: stack to be used
  * @line_number: interpreted line number
  */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	char numbuf[17];

	if (pointer)
		printf("%d\n", pointer->n);
	else
	{
		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": can't pint, stack empty\n", 26);
		exit(EXIT_FAILURE);
	}
}

/**
  * pchar - prints value of the top as a char
  * @stack: stack to be used
  * @line_number: interpreted line number
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	char numbuf[17];

	if (pointer)
	{
		if (pointer->n < 0 || pointer->n > 127)
		{
			write(STDERR_FILENO, "L", 1);
			citoa(line_number, numbuf);
			write(STDERR_FILENO, numbuf, strlen(numbuf));
			write(STDERR_FILENO, ": can't pchar, value out of range\n", 34);
			exit(EXIT_FAILURE);
		}
		printf("%c\n", pointer->n);
	}
	else
	{
		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": can't pchar, stack empty\n", 27);
		exit(EXIT_FAILURE);
	}
}

/**
  * pstr - prints string starting at top of stack, followed by a new line
  * @stack: stack to be used
  * @line_number: interpreted line number
  */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	(void) line_number;

	while (pointer && pointer->n > 0 && pointer->n <= 127)
	{
		printf("%c", pointer->n);
		pointer = pointer->next;
	}
	printf("\n");
}
