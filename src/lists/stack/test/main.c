#include "stack.h"

#include <stdio.h>

void	del_node_content(void *content)
{
	content = NULL;
}

int	is_equal(void *self_content, void *content)
{
	return (*(int *)self_content == *(int *)content);
}

int main()
{
	t_stack *stack = new_stack();
	t_stack *stack2 = new_stack();
	int	numbers[4] = {3, 2, 4, 9};
	t_stack_node *three = stack->create_node(&(numbers[0]));
	t_stack_node *two = stack->create_node(&(numbers[1]));
	t_stack_node *four = stack->create_node(&(numbers[2]));
	t_stack_node *nine = stack->create_node(&(numbers[3]));

	t_stack_node *current;
	// printf("pointer = %p, data = %d", three->content, *(int *)three->content);
	stack->push(stack, three);
	stack->push(stack, two);
	stack->push(stack, four);
	stack->push_unique(stack, three, is_equal);
	printf("oi\n");
	stack->push(stack, three);
	stack->push_unique(stack, three, is_equal);
	stack->push_unique(stack, nine, is_equal);

	int eight = 8;
	int includes = stack->includes(stack, &eight, is_equal);
	printf("stack includes 8 = %d\n", includes);
	includes = stack->includes(stack, &(numbers[1]), is_equal);
	printf("stack includes 2 = %d\n", includes);

	stack->transfer_top(stack, stack2);
	stack->transfer_top(stack, stack2);
	stack->transfer_top(stack, stack2);
	// stack->rotate(&stack, 1);
	// ------------------------------------
	current = stack2->pop(stack2);
	printf("pointer = %p, data = %d\n", current->content, *(int *)current->content);
	stack->push(stack, current);
	// ------------------------------------
	current = stack2->pop(stack2);
	printf("pointer = %p, data = %d\n", current->content, *(int *)current->content);
	stack->push(stack, current);
	// ------------------------------------
	current = stack2->pop(stack2);
	printf("pointer = %p, data = %d\n", current->content, *(int *)current->content);
	stack->push(stack, current);
	stack->destroy(&stack, del_node_content);
	stack2->destroy(&stack2, del_node_content);
}
