/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:35:01 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/13 14:26:51 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack_node
{
	void				*content;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	unsigned int	length;
	t_stack_node	**bottom_ref;
	t_stack_node	**top_ref;
	t_stack_node	*(*create_node)(void *content);
	int				(*swap_first_node)(struct s_stack *stack, t_stack_node **node);
	int				(*rotate)(struct s_stack **self, int reverse);
	int				(*push)(struct s_stack **self_ref, t_stack_node **node_ref);
	t_stack_node	*(*pop)(struct s_stack **self_ref);
	int				(*transfer_top)(struct s_stack **self_ref, struct s_stack **other_stack_ref);
	int				(*destroy)(struct s_stack **self_ref, void (*del_node_content)(void *content));
}	t_stack;

t_stack			*new_stack();
t_stack_node	*stack_new_node(void *content);
int				stack_swap_first_node(t_stack *stack, t_stack_node **first_node_ref);
int				stack_rotate(t_stack **self_ref, int reverse);
int				stack_push(t_stack **self_ref, t_stack_node **node_ref);
t_stack_node	*stack_pop(t_stack **self_ref);
int				stack_transfer_top(t_stack **self_ref, t_stack **other_stack_ref);
int				stack_destroy(t_stack **self_ref, void (*del_node_content)(void *content));

#endif
