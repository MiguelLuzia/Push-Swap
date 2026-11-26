/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:10 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/26 10:42:50 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_sqrt(int n)
{
	int	i;

	if (n <= 1)
		return (1);
	i = 1;
	while (i + 1 <= n / (i + 1))
		i++;
	return (i);
}

static void	push_chunks(t_data *data, int chunk_size)
{
	int	limit;
	int	pushed;
	int	total;

	total = stack_size(data->a);
	limit = chunk_size;
	pushed = 0;
	while (pushed < total)
	{
		if (data->a->index < limit)
		{
			pb(data);
			pushed++;
		}
		else
			ra(data);
		if (pushed >= limit)
			limit += chunk_size;
	}
}

void	sort_medium(t_data *data)
{
	int	n;

	n = stack_size(data->a);
	push_chunks(data, n / calc_sqrt(n));
	while (data->b)
	{
		rotate_b_top(data, find_max(data->b));
		pa(data);
	}
}
