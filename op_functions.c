#include "monty.h"

/**
  * push - pushes an element to the stack
  * @stack: stack to be pushed to
  * @line_number: interpreted line number
  */
void push(stack_t **stack, unsigned int line_number)
{
	char *tok = strtok(NULL, " "), numbuf[17];

	if (tok && isint(tok))
	{
		stack_push(stack, atoi(tok));
	}
	else
	{
		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": usage: push integer\n", 22);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
  * pop - removes top
  * @stack: stack to be modified
  * @line_number: interpreted line number
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer;
	char numbuf[17];

	if (stack && *stack)
	{
		pointer = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(pointer);
	}
	else
	{
		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": can't pop an empty stack\n", 27);
		exit(EXIT_FAILURE);
	}
}

/**
  * swap - swaps two top elements
  * @stack: stack to be modified
  * @line_number: interpreted line number
  */
void swap(stack_t **stack, unsigned int line_number)
{
	char numbuf[17];

	if (stack && *stack && (*stack)->next)
	{
		int temp = (*stack)->n ^ (*stack)->next->n;
		(*stack)->n ^= temp;
		(*stack)->next->n ^= temp;
	}
	else
	{
		write(STDERR_FILENO, "L", 1);
		citoa(line_number, numbuf);
		write(STDERR_FILENO, numbuf, strlen(numbuf));
		write(STDERR_FILENO, ": can't swap, stack too short\n", 30);
		exit(EXIT_FAILURE);
	}
}
