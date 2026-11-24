/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:13 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 13:56:49 by dboryey          ###   ########.fr       */
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

t_stack	*new_stack(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (new);
	new->value = n;
	new->next = NULL;
	return (new);
}

void	add_back(t_data *data, int n)
{
	t_stack	*num;

	num = new_stack(n);
	if (!num)
		exit_error(data);
	add_back(&data->a, num);
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