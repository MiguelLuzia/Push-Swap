/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:41:58 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/23 18:46:52 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_top(t_stack **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	tmp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp;
	return (1);
}

void	sa(t_data *data)
{
	if (swap_top(&data->a))
		write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	if (swap_top(&data->b))
		write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = swap_top(&data->a);
	swapped_b = swap_top(&data->b);
	if (swapped_a || swapped_b)
		write(1, "ss\n", 3);
}

/* stack_find.c */
/* Read-only stack queries: min, max, position of an element and is_sorted. */