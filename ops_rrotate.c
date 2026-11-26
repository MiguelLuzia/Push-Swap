/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:41:57 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/26 10:41:07 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rrotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_data *data)
{
	if (rrotate(&data->a))
		emit_op(data, OP_RRA, "rra\n");
}

void	rrb(t_data *data)
{
	if (rrotate(&data->b))
		emit_op(data, OP_RRB, "rrb\n");
}

void	rrr(t_data *data)
{
	int	rrotated_a;
	int	rrotated_b;

	rrotated_a = rrotate(&data->a);
	rrotated_b = rrotate(&data->b);
	if (rrotated_a || rrotated_b)
		emit_op(data, OP_RRR, "rrr\n");
}
