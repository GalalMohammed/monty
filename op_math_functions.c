#include "monty.h"

/**
  * add - adds tow top element
  * @stack: stack to be used
  * @line_number: interpreted line number
  */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		char numbuf[17];

		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": can't add, stack too short\n", 29);
		exit(EXIT_FAILURE);
	}
}

/**
  * sub - subtracts top element from second top one
  * @stack: stack to be used
  * @line_number: interpreted line number
  */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		char numbuf[17];

		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": can't sub, stack too short\n", 29);
		exit(EXIT_FAILURE);
	}
}
