/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:41:58 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/25 23:34:18 by mitavare         ###   ########.fr       */
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
		emit_op(data, OP_SA, "sa\n");
}

void	sb(t_data *data)
{
	if (swap_top(&data->b))
		emit_op(data, OP_SB, "sb\n");
}

void	ss(t_data *data)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = swap_top(&data->a);
	swapped_b = swap_top(&data->b);
	if (swapped_a || swapped_b)
		emit_op(data, OP_SS, "ss\n");
}

/* stack_find.c */
/* Read-only stack queries: min, max, position of an element and is_sorted. */