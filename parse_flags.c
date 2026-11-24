/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 17:12:12 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 17:36:21 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_flags(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strncmp(av[i], "--simple", 9))
			data->strategy = STRAT_SIMPLE;
		else if (!ft_strncmp(av[i], "--medium", 9))
			data->strategy = STRAT_MEDIUM;
		else if (!ft_strncmp(av[i], "--complex", 10))
			data->strategy = STRAT_COMPLEX;
		else if (!ft_strncmp(av[i], "--adaptive", 11))
			data->strategy = STRAT_ADAPTIVE;
		else if (!ft_strncmp(av[i], "--bench", 8))
			data->bench = 1;
		i++;
	}
}
