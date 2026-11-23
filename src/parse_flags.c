/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:14:58 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/23 18:45:53 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* parse_flags.c */
/* Reads the leading "--" arguments (--simple, --medium, --complex, --adaptive, --bench). */
/* Returns the index of the first number, or -1 on an unknown or duplicate flag. */