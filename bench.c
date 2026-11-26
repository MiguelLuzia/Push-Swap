/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:14:55 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/26 10:40:33 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_stat(char *name, size_t n)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd((int)n, 2);
	ft_putchar_fd(' ', 2);
}

static void	put_disorder(double d)
{
	long	v;

	v = (long)(d * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(v / 100), 2);
	ft_putchar_fd('.', 2);
	if (v % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd((int)(v % 100), 2);
	ft_putstr_fd("%\n", 2);
}

static void	put_strategy(t_data *data)
{
	int	used;

	used = data->strategy;
	if (used == STRAT_ADAPTIVE)
		used = pick_method(data->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (data->strategy == STRAT_ADAPTIVE)
		ft_putstr_fd("Adaptive / ", 2);
	else if (used == STRAT_SIMPLE)
		ft_putstr_fd("Simple / ", 2);
	else if (used == STRAT_MEDIUM)
		ft_putstr_fd("Medium / ", 2);
	else
		ft_putstr_fd("Complex / ", 2);
	if (used == STRAT_SIMPLE)
		ft_putstr_fd("O(n^2)\n", 2);
	else if (used == STRAT_MEDIUM)
		ft_putstr_fd("O(n*sqrt(n))\n", 2);
	else
		ft_putstr_fd("O(n log n)\n", 2);
}

static void	put_counts(t_stats *s)
{
	ft_putstr_fd("[bench] ", 2);
	put_stat("sa", s->ops[OP_SA]);
	put_stat("sb", s->ops[OP_SB]);
	put_stat("ss", s->ops[OP_SS]);
	put_stat("pa", s->ops[OP_PA]);
	put_stat("pb", s->ops[OP_PB]);
	ft_putstr_fd("\n[bench] ", 2);
	put_stat("ra", s->ops[OP_RA]);
	put_stat("rb", s->ops[OP_RB]);
	put_stat("rr", s->ops[OP_RR]);
	put_stat("rra", s->ops[OP_RRA]);
	put_stat("rrb", s->ops[OP_RRB]);
	put_stat("rrr", s->ops[OP_RRR]);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_data *data)
{
	put_disorder(data->disorder);
	put_strategy(data);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd((int)data->stats.total, 2);
	ft_putchar_fd('\n', 2);
	put_counts(&data->stats);
}
