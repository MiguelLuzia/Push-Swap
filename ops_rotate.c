/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:41:56 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/25 23:33:06 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	return (1);
}

void	ra(t_data *data)
{
	if (rotate(&data->a))
		emit_op(data, OP_RA, "ra\n");
}

void	rb(t_data *data)
{
	if (rotate(&data->b))
		emit_op(data, OP_RB, "rb\n");
}

void	rr(t_data *data)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(&data->a);
	rotated_b = rotate(&data->b);
	if (rotated_a || rotated_b)
		emit_op(data, OP_RR, "rr\n");
}

/* ops_rotate.c */
/* Rotate operations ra, rb and rr. The top node becomes the last one, */
/* then the operation is printed and counted. */