/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:09 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/26 18:01:53 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int n)
{
	int	bits;

	bits = 0;
	while (((n - 1) >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass(t_data *data, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((data->a->index >> bit) & 1) == 1)
			ra(data);
		else
			pb(data);
		i++;
	}
	while (data->b)
		pa(data);
}

void	sort_complex(t_data *data)
{
	int	size;
	int	bits;
	int	bit;

	size = stack_size(data->a);
	bits = max_bits(size);
	bit = 0;
	while (bit < bits && !is_sorted(data->a))
	{
		radix_pass(data, bit, size);
		bit++;
	}
}
