/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:14:55 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/26 10:58:31 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_disorder(t_stack *stack)
{
	long		mistake;
	long		t_pairs;
	t_stack		*current;

	mistake = 0;
	t_pairs = 0;
	while (stack)
	{
		current = stack->next;
		while (current)
		{
			t_pairs++;
			if (stack->value > current->value)
				mistake++;
			current = current->next;
		}
		stack = stack->next;
	}
	if (t_pairs == 0)
		return (0.0);
	return ((double)mistake / (double)t_pairs);
}

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*other;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		other = stack;
		while (other)
		{
			if (other->value < current->value)
				index++;
			other = other->next;
		}
		current->index = index;
		current = current->next;
	}
}
