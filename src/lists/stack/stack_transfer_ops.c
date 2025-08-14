/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_transfer_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:04:52 by valero            #+#    #+#             */
/*   Updated: 2025/08/14 18:25:12 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push(t_stack **self_ref, t_stack_node **node_ref)
{
	// t_stack			*self;
	// t_stack_node	*node;

	// self = *self_ref;
	// node = *node_ref;
	if (!self_ref || !*self_ref || !node_ref || !(*node_ref))
		return (0);
	(*node_ref)->next = NULL;
	(*self_ref)->length++;
	if ((*self_ref)->length == 1)
	{
		(*self_ref)->bottom_ref = node_ref;
		(*self_ref)->top_ref = node_ref;
		(*node_ref)->prev = NULL;
		return (1);
	}
	(*(*self_ref)->top_ref)->next = (*node_ref);
	(*node_ref)->prev = *(*self_ref)->top_ref;
	(*self_ref)->top_ref = node_ref;
	return (1);
}

t_stack_node	*stack_pop(t_stack **self_ref)
{
	// t_stack			*self;
	t_stack_node	*popped_node;

	// self = *self_ref;
	if (!self_ref || !(*self_ref) || !(*self_ref)->length)
		return (NULL);
	(*self_ref)->length--;
	popped_node = *(*self_ref)->top_ref;
	*(*self_ref)->top_ref = popped_node->prev;
	popped_node->next = NULL;
	popped_node->prev = NULL;
	return (popped_node);
}

int	stack_transfer_top(t_stack **self_ref, t_stack **other_stack_ref)
{
	t_stack			*self;
	t_stack			*other_stack;
	t_stack_node	*transfered_node;
	int				transference_succeeded;

	transfered_node = NULL;
	self = *self_ref;
	other_stack = *other_stack_ref;
	if (!self_ref || !self || !other_stack_ref || !other_stack || !self->length)
		return (0);
	transfered_node = self->pop(self_ref);
	transference_succeeded = other_stack->push(other_stack_ref, &transfered_node);
	if (!transference_succeeded)
		self->push(self_ref, &transfered_node);
	return (transference_succeeded);
}
