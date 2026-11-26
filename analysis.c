/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:14:55 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/26 00:15:48 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_disorder(t_stack *stack)
{
	long		mistake;
	long		t_pairs;
	t_stack	*current;

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

// alterações muito pequenas, so para corrigir uns erros de compilação do make

/* analysis.c */
/* Pre-sort analysis: compute_disorder (mistaken pairs / total pairs) */
/* and the rank indexing that replaces each value by its position in sorted order. */