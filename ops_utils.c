/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitavare <mitavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:29:43 by mitavare          #+#    #+#             */
/*   Updated: 2026/11/25 23:36:24 by mitavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	emit_op(t_data *data, t_op op, char *name)
{
	write(1, name, ft_strlen(name));
	data->stats.ops[op]++;
	data->stats.total++;
}
/*
Sobre o porque de ter usado esta função:
o --bench obriga a mostrar quantas operações sao feitas no total e quantas de cada tipo, esta função serve
para dar write da operação + fazer essas contagens
*/