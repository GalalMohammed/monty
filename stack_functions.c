#include "monty.h"

/**
  * stack_push - inserts an element into the stack
  * @data: num to be pushed
  * @stack: stack to be pushed into
  */
void stack_push(stack_t **stack, int data)
{
	stack_t *pointer = malloc(sizeof(stack_t));

	if (pointer == NULL)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", 21);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		pointer->n = data;
		pointer->next = *stack;
		pointer->prev = NULL;
		if (*stack != NULL)
			(*stack)->prev = pointer;
		*stack = pointer;
	}
}

/**
  * free_stack - frees the stack
  * @stack: stack to be freed
  */
void free_stack(stack_t **stack)
{
	stack_t *ptr = *stack;

	while (stack && *stack)
	{
		*stack = (*stack)->next;
		free(ptr);
		ptr = *stack;
	}
}
