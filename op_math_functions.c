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

/**
  * _div - divides second top element by top one
  * @stack: stack to be used
  * @line_number: interpreted line number
  */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack && (*stack)->next)
	{
		if ((*stack)->n)
		{
			(*stack)->next->n /= (*stack)->n;
			pop(stack, line_number);
		}
		else
		{
			char numbuf[17];

			write(STDERR_FILENO, "L", 1);
			citoa(line_number, numbuf);
			write(STDERR_FILENO, numbuf, strlen(numbuf));
			write(STDERR_FILENO, ": division by zero\n", 19);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		char numbuf[17];

		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": can't div, stack too short\n", 29);
		exit(EXIT_FAILURE);
	}
}

/**
  * mul - multiplie top element with second top one
  * @stack: stack to be used
  * @line_number: interpreted line number
  */
void mul(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack && (*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		char numbuf[17];

		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": can't mul, stack too short\n", 29);
		exit(EXIT_FAILURE);
	}
}

/**
  * mod - computes the rest of division of second top of stack by top one
  * @stack: stack to be used
  * @line_number: interpreted line number
  */
void mod(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack && (*stack)->next)
	{
		if ((*stack)->n)
		{
			(*stack)->next->n %= (*stack)->n;
			pop(stack, line_number);
		}
		else
		{
			char numbuf[17];

			write(STDERR_FILENO, "L", 1);
			citoa(line_number, numbuf);
			write(STDERR_FILENO, numbuf, strlen(numbuf));
			write(STDERR_FILENO, ": division by zero\n", 19);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		char numbuf[17];

		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": can't mod, stack too short\n", 29);
		exit(EXIT_FAILURE);
	}
}
