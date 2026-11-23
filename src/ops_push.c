/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:41:56 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/23 18:47:22 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_top(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !dst || !*src)
		return (0);
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
	return (1);
}

void	pa(t_data *data)
{
	if (push_top(&data->a, &data->b))
		write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	if (push_top(&data->b, &data->a))
		write(1, "pb\n", 3);
}

/* ops_push.c */
/* Push operations pa and pb. Moves the top node from one stack to the other, */
/* prints the operation and counts it. */