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
	t_stack_node	**bottom;
	t_stack_node	**top;
	int				(*swap_first_node)(t_stack *stack, t_stack_node **node);
	int				(*swap_tops)(t_stack **self, t_stack **other_stack);
	int				(*rotate)(t_stack **self, int reverse);
}	t_stack;

t_stack_node	*new_stak_node(void *content);
t_stack			*new_stack();

#endif
