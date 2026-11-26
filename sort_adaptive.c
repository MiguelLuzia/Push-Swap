/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:09 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/25 23:42:10 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pick_method(double disorder)
{
	if (disorder < 0.2)
		return (STRAT_SIMPLE);
	if (disorder < 0.5)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

void	sort_adaptive(t_data *data)
{
	int	method;

	if (sort_small(data))
		return ;
	method = pick_method(data->disorder);
	if (method == STRAT_SIMPLE)
		sort_simple(data);
	else if (method == STRAT_MEDIUM)
		sort_medium(data);
	else
		sort_complex(data);
}

/* sort_adaptive.c */
/* Adaptive strategy: picks the simple, medium or complex method */
/* from the measured disorder (< 0.2, < 0.5, otherwise). */