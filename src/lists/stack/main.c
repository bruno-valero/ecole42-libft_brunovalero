#include "stack.h"

int	swap_first_node(t_stack_node **node)
{
	t_stack_node	*first_node;
	t_stack_node	*third_node;

	first_node = (*node);
	third_node = (*node)->next->next;
	(*node)->next->next = first_node;
	(*node)->next = third_node;
	return (1);
}

#include <stdio.h>

int main()
{

	int	numbers[3] = {3, 2, 4};
	t_stack_node *three = new_stak_node(&(numbers[0]));
	t_stack_node *two = new_stak_node(&(numbers[1]));
	t_stack_node *four = new_stak_node(&(numbers[2]));

	printf("pointer = %p, data = %d", three->content, *(int *)three->content);
	three->next = two;
	two->next = four;
	swap_first_node(&three);
}
