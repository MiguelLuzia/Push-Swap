/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:14:57 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 13:00:12 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_free(t_data *data)
{
	if (!data)
		return ;
	stack_free(&data->a);
	stack_free(&data->b);
}

void	exit_error(t_data *data)
{
	data_free(data);
	write(2, "Error\n", 6);
	exit(1);
}

void	data_init(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->strategy = STRAT_ADAPTIVE;
	data->bench = 0;
	data->disorder = 0.0;
	ft_bzero(&data->stats, sizeof(t_stats));
}

/* data.c */
/* Lifecycle of the t_data struct: data_init, data_free and exit_error. */
/* exit_error frees all memory, prints "Error" on stderr and exits. */