/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:13 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 14:32:49 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

t_stack	*new_node(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (new);
	new->value = n;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
}

void	add_value(t_data *data, int n)
{
	t_stack	*node;

	node = new_node(n);
	if (!node)
		exit_error(data);
	add_back(&data->a, node);
}

size_t	stack_size(t_stack *stack)
{
	size_t	n;

	n = 0;
	while (stack)
	{
		stack = stack->next;
		n++;
	}
	return (n);
}

/* stack.c */
/* Basic linked-list functions for t_stack: create a node, add to the back, */
/* get the size and free the whole stack. */