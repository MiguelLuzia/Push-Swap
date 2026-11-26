/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:29:43 by mitavare          #+#    #+#             */
/*   Updated: 2026/11/26 10:41:20 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	emit_op(t_data *data, t_op op, char *name)
{
	write(1, name, ft_strlen(name));
	data->stats.ops[op]++;
	data->stats.total++;
}
