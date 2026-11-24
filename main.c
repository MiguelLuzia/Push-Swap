/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:42:02 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 17:17:13 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_data *data)
{
	if (data->strategy == STRAT_SIMPLE)
		sort_simple(data);
	else if (data->strategy == STRAT_MEDIUM)
		sort_medium(data);
	else if (data->strategy == STRAT_COMPLEX)
		sort_complex(data);
	else
		sort_adaptive(data);
}

int	main(int ac, char **av)
{
	t_data	storage;
	t_data	*data;

	data = &storage;
	data_init(data);
	parse_flags(ac, av, data);
	if (!parse_args(ac, av, &data->a))
		exit_error(data);
	if (!data->a)
		return (0);
	assign_index(data->a);
	data->disorder = calc_disorder(data->a);
	if (!is_sorted(data->a))
		run_sort(data);
	if (data->bench)
		print_bench(data);
	data_free(data);
	return (0);
}

/* main.c */
/* Entry point. Parses flags and numbers, computes disorder, picks the strategy, */
/* runs the sort, prints the bench report if asked, then frees everything. */