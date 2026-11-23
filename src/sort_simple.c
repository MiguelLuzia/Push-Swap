/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:11 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/23 18:48:03 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort_simple.c */
/* O(n^2) strategy: repeatedly find the minimum, rotate it to the top, */
/* push it to b, then push everything back to a. */