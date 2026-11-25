/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:12 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/25 13:14:13 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	if (calc_disorder(stack) == 0)
		return (1);
	return (0);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min->index = stack->index;
		stack = stack->next;
	}
	return (min);
}

void	find_max(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->index > max->index)
			max->index = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_pos(t_stack *stack, t_stack *find)
{
	int	pos;

	pos = 0;
	while (stack && stack != find)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

/* stack_find.c */
/* Read-only stack queries: min, max, position of an element and is_sorted. */