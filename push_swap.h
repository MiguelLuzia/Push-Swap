/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:41:37 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/27 13:38:42 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef enum s_strategy
{
	STRAT_NONE = 0,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE,
}	t_strategy;

typedef enum s_op
{
	OP_SA = 0,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_stats
{
	size_t	ops[11];
	size_t	total;
}	t_stats;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_strategy	strategy;
	int			bench;
	double		disorder;
	t_stats		stats;
}	t_data;

//analysis.c
double	calc_disorder(t_stack *stack);
void	assign_index(t_stack *stack);

// ops_utils.c
void	emit_op(t_data *data, t_op op, char *name);

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

//checks.c
void	check_dup(t_data *data);
int		has_value(t_stack *stack, int value);

//parsing.c
int		parse_args(int ac, char **av, t_stack **a);

//data.c
void	data_init(t_data *data);
void	data_free(t_data *data);
void	exit_error(t_data *data);
void	ft_free_split(char **tokens);

//stack.c
void	stack_free(t_stack **stack);
t_stack	*new_node(int n);
void	add_back(t_stack **head, t_stack *node);
int		stack_size(t_stack *stack);

//stack_find.c
int		is_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
int		find_pos(t_stack *stack, t_stack *find);

//parse_flags.c
void	parse_flags(int ac, char **av, t_data *data);

//rotate_utils
void	rotate_a_top(t_data *data, t_stack *num);

void	rotate_b_top(t_data *data, t_stack *num);

//sort_simple
void	sort_simple(t_data *data);

//sort_medium.c
void	sort_medium(t_data *data);

//sort_complex.c
void	sort_complex(t_data *data);

//sort_adaptive.c
int		pick_method(double disorder);
void	sort_adaptive(t_data *data);

//sort_small.c
int		sort_small(t_data *data);

//bench.c
void	print_bench(t_data *data);

#endif