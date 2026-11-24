/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:15:09 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 12:24:23 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort_adaptive.c */
/* Adaptive strategy: picks the simple, medium or complex method */
/* from the measured disorder (< 0.2, < 0.6, otherwise). */