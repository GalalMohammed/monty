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
