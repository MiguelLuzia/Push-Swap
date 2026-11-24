/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:41:37 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 11:04:33 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int				value; //the number itself in stack
	int				index; //index of the number in stack
	struct s_stack	*next; //pointer to the next number in stack
}	t_stack;

typedef enum s_strategy
{
	STRAT_NONE = 0, //STRAT_NONE is for selecting adaptive sorting
	STRAT_SIMPLE, //For *0.00 < disorder < 0.20*
	STRAT_MEDIUM, //For *0.20 <= disorder <= 0.60*
	STRAT_COMPLEX, //For *0.60 < disorder <= 1.00*
	STRAT_ADAPTIVE //For when no strategy selected
}	t_strategy;

typedef struct s_stats
{
	size_t	ops[11]; //All of the 11 operations from ops_
	size_t	total; //total of operations
}	t_stats;

typedef struct s_data
{
	t_stack		*a; //stack a
	t_stack		*b; //stack b
	t_strategy	strategy; //selected strategy
	int			bench; //--bench mode
	double		disorder; //disorder coeficient, has to be double to be more precise that float.
	t_stats		stats; //status struct that has the ops_ and the total
}	t_data;

//ops_swap.c
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

//ops_push.c
void	pa(t_data *data);
void	pb(t_data *data);

//ops_rotate.c
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

//ops_rrotate.c
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

//data.c
void	data_free(t_data *data);
void	exit_error(t_data *data);

//stack.c
void	stack_free(t_stack **stack);
t_stack	*new_stack(int n);
void	add_back(t_stack **stack, t_stack *new);
size_t	stack_size(t_stack *stack);

#endif