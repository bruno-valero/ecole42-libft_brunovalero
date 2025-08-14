/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:04:52 by valero            #+#    #+#             */
/*   Updated: 2025/08/14 18:06:54 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_swap_first_node(t_stack *stack, t_stack_node **first_node_ref)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	t_stack_node	*third_node;

	first_node = (*first_node_ref);
	if (!stack || !first_node_ref || *first_node_ref || !first_node->next || stack->length < 2)
		return (0);

	if (stack->bottom_ref == &first_node)
		stack->bottom_ref = &(first_node->next);
	if (stack->top_ref == &(first_node->next))
		stack->top_ref = &first_node;

	second_node = first_node->next;
	third_node = second_node->next;
	second_node->prev = NULL;
	second_node->next = first_node;
	first_node->prev = second_node;
	first_node->next = third_node;
	return (1);
}
static void	stack_rotate_run(t_stack_node	**top_ref, t_stack_node	**bottom_ref, int reverse)
{
	if (!reverse)
	{
		(*top_ref)->next = (*bottom_ref);
		(*bottom_ref)->prev = (*top_ref);
		*bottom_ref = *top_ref;
		*top_ref = (*top_ref)->prev;
		(*top_ref)->next = NULL;
		(*bottom_ref)->prev = NULL;
		return ;
	}
	(*top_ref)->next = (*bottom_ref);
	(*bottom_ref)->prev = (*top_ref);
	*top_ref = *bottom_ref;
	*bottom_ref = (*bottom_ref)->next;
	(*bottom_ref)->prev = NULL;
	(*top_ref)->next = NULL;
}

int	stack_rotate(t_stack **self_ref, int reverse)
{
	t_stack			*self;
	t_stack_node	**top_ref;
	t_stack_node	**bottom_ref;

	self = *self_ref;
	if (!self_ref || !self || self->length < 2)
		return (0);
	top_ref = self->top_ref;
	bottom_ref = self->bottom_ref;
	stack_rotate_run(top_ref, bottom_ref, reverse);
	return (1);
}
