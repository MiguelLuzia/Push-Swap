/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:07 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/26 10:42:35 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_top(t_data *data, t_stack *num)
{
	int	pos;
	int	size;

	size = stack_size(data->a);
	pos = find_pos(data->a, num);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(data);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(data);
			pos++;
		}
	}
}

void	rotate_b_top(t_data *data, t_stack *num)
{
	int	pos;
	int	size;

	size = stack_size(data->b);
	pos = find_pos(data->b, num);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(data);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(data);
			pos++;
		}
	}
}
