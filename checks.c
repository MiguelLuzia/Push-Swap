/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:14:56 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 13:27:18 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_data *data)
{
	t_stack	*stack;
	t_stack	*current;

	stack = data->a;
	while (stack)
	{
		current = stack->next;
		while (current)
		{
			if (stack->value == current->value)
				exit_error(data);
			current = current->next;
		}
		stack = stack->next;
	}
}

int	has_value(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	validate()
{
	
}

/* checks.c */
/* Input validation: is the string a valid number, does it fit in an int, */
/* and is there a duplicate in the stack. */