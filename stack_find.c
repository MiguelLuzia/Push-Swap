/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:12 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 17:41:48 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	if (calc_disorder(stack) == 0)
		return (1);
	return (0);
}

/* stack_find.c */
/* Read-only stack queries: min, max, position of an element and is_sorted. */