/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:11 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/26 10:42:58 by dboryey          ###   ########.fr       */
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
