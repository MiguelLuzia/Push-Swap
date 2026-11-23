/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:41:56 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/23 18:47:29 by dboryey          ###   ########.fr       */
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
		write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	if (rotate(&data->b))
		write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(&data->a);
	rotated_b = rotate(&data->b);
	if (rotated_a || rotated_b)
		write(1, "rr\n", 3);
}

/* ops_rotate.c */
/* Rotate operations ra, rb and rr. The top node becomes the last one, */
/* then the operation is printed and counted. */