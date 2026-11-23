/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:10 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/23 18:48:10 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort_medium.c */
/* O(n * sqrt(n)) strategy: split ranks into about sqrt(n) chunks, */
/* push them to b chunk by chunk, then bring the largest back to a. */