#include "stack.h"

#include <stdio.h>

int main()
{
	t_stack *stack = new_stack();
	t_stack *stack2 = new_stack();
	int	numbers[3] = {3, 2, 4};
	t_stack_node *three = stack->create_node(&(numbers[0]));
	t_stack_node *two = stack->create_node(&(numbers[1]));
	t_stack_node *four = stack->create_node(&(numbers[2]));

	t_stack_node *current;
	// printf("pointer = %p, data = %d", three->content, *(int *)three->content);
	stack->push(&stack, &three);
	stack->push(&stack, &two);
	stack->push(&stack, &four);

	stack->transfer_top(&stack, &stack2);
	stack->transfer_top(&stack, &stack2);
	stack->transfer_top(&stack, &stack2);
	// stack->rotate(&stack, 1);
	// ------------------------------------
	current = stack2->pop(&stack2);
	printf("pointer = %p, data = %d\n", current->content, *(int *)current->content);
	// ------------------------------------
	current = stack2->pop(&stack2);
	printf("pointer = %p, data = %d\n", current->content, *(int *)current->content);
	// ------------------------------------
	current = stack2->pop(&stack2);
	printf("pointer = %p, data = %d\n", current->content, *(int *)current->content);
	// swap_first_node(&three);
}
