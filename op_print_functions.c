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
