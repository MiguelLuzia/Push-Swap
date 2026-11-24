/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:14:55 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 12:24:54 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_disorder(t_stack *stack)
{
	int		mistake;
	int		t_pairs;
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

/* analysis.c */
/* Pre-sort analysis: compute_disorder (mistaken pairs / total pairs) */
/* and the rank indexing that replaces each value by its position in sorted order. */