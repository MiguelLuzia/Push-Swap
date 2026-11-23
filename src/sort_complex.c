/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:09 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/23 18:48:17 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort_complex.c */
/* O(n log n) strategy: radix sort on the ranks, one bit per pass, */
/* using pb/pa to separate zeros and ones. */