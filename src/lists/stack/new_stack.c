/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:16:46 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/13 20:49:29 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	swap_first_node(t_stack *stack, t_stack_node **node)
{
	t_stack_node	*first_node;
	t_stack_node	*third_node;

	if (!stack || !node || *node || !(*node)->next || stack->length < 2)
		return (0);

	if (stack->head == *node)
		stack->head = (*node)->next;
	if (stack->tail == (*node)->next)
		stack->tail = *node;

	first_node = (*node);
	third_node = (*node)->next->next;
	(*node)->next->next = first_node;
	(*node)->next = third_node;
	return (1);
}

int	swap_stacks_tail(t_stack **self, t_stack **other_stack)
{

}
