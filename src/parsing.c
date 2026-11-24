/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboryey <dboryey@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:14:57 by dboryey           #+#    #+#             */
/*   Updated: 2026/11/24 14:20:13 by dboryey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* parse_args.c */
/* Converts the remaining arguments (including "1 2 3" strings) into the nodes of stack a. */
/* Calls the checks and exits with an error on any invalid input. */

void	ft_free_split(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static int	is_flag(const char *s)
{
	return (!ft_strncmp(s, "--simple", 9)
		|| !ft_strncmp(s, "--medium", 9)
		|| !ft_strncmp(s, "--complex", 10)
		|| !ft_strncmp(s, "--adaptive", 11)
		|| !ft_strncmp(s, "--bench", 8));
}

static int	parse_int(const char *s, int *out)
{
	long	n;
	int		sign;

	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!ft_isdigit(*s))
		return (0);
	n = 0;
	while (ft_isdigit(*s))
	{
		n = n * 10 + (*s - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		s++;
	}
	if (*s != '\0')
		return (0);
	*out = (int)(n * sign);
	return (1);
}

static int	add_token(t_stack **a, const char *token)
{
	int		value;
	t_stack	*node;

	if (!parse_int(token, &value) || has_value(*a, value))
		return (0);
	node = new_stack(value);
	if (!node)
		return (0);
	add_back(a, node);
	return (1);
}

static int	parse_one(t_stack **a, const char *arg)
{
	char	**tokens;
	int		i;
	int		ok;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	i = 0;
	ok = (tokens[0] != NULL);
	while (ok && tokens[i])
	{
		ok = add_token(a, tokens[i]);
		i++;
	}
	ft_free_split(tokens);
	return (ok);
}

int	parse_args(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1; //acho q deve comecar em 1, porque logo a seguir tu verificas o ac[0], o nome do executavel.
	*a = NULL;
	while (i < ac)
	{
		if (!is_flag(av[i]) && !parse_one(a, av[i]))
		{
			stack_free(a);
			return (0);
		}
		i++;
	}
	return (1);
}
