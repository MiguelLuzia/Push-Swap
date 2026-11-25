/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:11 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/25 13:09:27 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_data *data)
{
	t_stack	*min;
	
	min = find_min(data->a);
	while (min)
	{
		rotate_a_top(data, min);
		pb(data);
		min = find_min(data->a);
	}
	while (data->b)
		pa(data);
}

/* sort_simple.c */
/* O(n^2) strategy selection sort: repeatedly find the minimum, rotate it to the top, */
/* push it to b, then push everything back to a. */