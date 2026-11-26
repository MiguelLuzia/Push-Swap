/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:11 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/25 23:53:49 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_data *data)
{
	t_stack	*max;

	max = find_max(data->a);
	if (data->a == max)
		ra(data);
	else if (data->a->next == max)
		rra(data);
	if (data->a->index > data->a->next->index)
		sa(data);
}

int	sort_small(t_data *data)
{
	if (stack_size(data->a) > 5)
		return (0);
	while (stack_size(data->a) > 3)
	{
		rotate_a_top(data, find_min(data->a));
		pb(data);
	}
	if (stack_size(data->a) == 3)
		sort_three(data);
	else if (data->a->index > data->a->next->index)
		sa(data);
	while (data->b)
		pa(data);
	return (1);
}

/* sort_small.c */
/* Hardcoded sorting for tiny stacks (2, 3 and 5 elements) */
/* using the fewest possible operations. */