/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:16:46 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/14 13:00:47 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	swap_first_node(t_stack *stack, t_stack_node **node)
{
	t_stack_node	*first_node;
	t_stack_node	*third_node;

	if (!stack || !node || *node || !(*node)->next || stack->length < 2)
		return (0);

	if (stack->bottom == &(*node))
		stack->bottom = &((*node)->next);
	if (stack->top == &((*node)->next))
		stack->top = &(*node);

	first_node = (*node);
	third_node = (*node)->next->next;
	(*node)->next->next = first_node;
	(*node)->next = third_node;
	return (1);
}

int	swap_tops(t_stack **self, t_stack **other_stack)
{
	t_stack_node	**self_node_top;
	t_stack_node	**self_node_before_top;

	if (!self || !(*self) || !other_stack || !(*other_stack)
			|| (*self)->length < 2 || (*other_stack)->length < 2)
		return (0);
	self_node_before_top = &((*(*self)->top)->prev);
	self_node_top = (*self)->top;
	(*(*self)->top)->prev->next = (*(*other_stack)->top);
	(*(*self)->top) = (*(*other_stack)->top);
	(*self)->top = (*other_stack)->top;
	(*(*other_stack)->top)->prev->next = *self_node_top;
	(*(*other_stack)->top) = *self_node_top;
	(*other_stack)->top = self_node_top;
	return (1);
}
int	rotate(t_stack **self, int reverse)
{
	if (!self || !(*self) || (*self)->length < 2)
		return (0);
	if (!reverse)
	{
		(*(*self)->top)->next = (*(*self)->bottom);
		(*self)->bottom = (*self)->top;
		(*self)->top = &((*(*self)->top)->prev);
		(*(*self)->top)->next = NULL;
		(*(*self)->bottom)->prev = NULL;
		return (1);
	}
	(*(*self)->top)->next = (*(*self)->bottom);
	(*self)->top = (*self)->bottom;
	(*self)->bottom = &((*(*self)->bottom)->next);
	(*(*self)->bottom)->prev = NULL;
	(*(*self)->top)->next = NULL;
	return (1);
}

int	push(t_stack **self, t_stack_node **node)
{
	if (!self || !(*self) || !node || !(*node))
		return (0);
	(*node)->next = NULL;
	(*self)->length++;
	if ((*self)->length == 1)
	{
		(*self)->bottom = node;
		(*self)->top = node;
		(*node)->prev = NULL;
		return (1);
	}
	(*(*self)->top)->next = *node;
	(*node)->prev = *(*self)->top;
	(*self)->top = node;
	return (1);
}

t_stack_node	*pop(t_stack **self)
{
	t_stack_node	*node;

	if (!self || !(*self) || !(*self)->length)
		return (NULL);
	(*self)->length--;
	node = *(*self)->top;
	node->next = NULL;
	node->prev = NULL;
	(*self)->top = &((*(*self)->top)->prev);
	(*(*self)->top)->next = NULL;
	return (node);
}

t_stack	*new_stack()
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->length = 0;
	stack->bottom = NULL;
	stack->top = NULL;
	stack->swap_first_node = swap_first_node;
	stack->swap_tops = swap_tops;
	stack->rotate = rotate;
}
