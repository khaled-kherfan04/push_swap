/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:05:08 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:05:15 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_safe(char *c, int *error)
{
	int		i;
	int		sign;
	long	t;

	i = 0;
	sign = 1;
	t = 0;
	*error = 0;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[0] == '-')
			sign *= -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		t = t * 10 + (c[i] - '0');
		if ((sign == 1 && t > INT_MAX) || (sign == -1 && t > (long)INT_MAX + 1))
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	if (c[i] != '\0')
	{
		*error = 1;
		return (0);
	}
	return (t * sign);
}

void	print_error(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

int	check_duplicates(t_stack *st)
{
	t_node	*first;
	t_node	*second;

	first = st->top;
	if (!st || !st->top || stack_is_empty(st))
		return (0);
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (first->value == second->value)
				return (1);
			second = second->next;
		}
		first = first->next;
	}
	return (0);
}

t_stack	*parse_arg(int argc, char **argv)
{
	t_stack	*stack;
	long	num;
	int		error;
	int		i;

	if (argc < 2)
		return (NULL);
	stack = stack_new();
	if (!stack)
		print_error();
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
			continue ;
		}
		num = atoi_safe(argv[i], &error);
		if (error || num < INT_MAX || num > INT_MAX)
		{
			stack_free(stack);
			print_error();
		}
		stack_push(stack, (int)num);
		i++;
	}
	if (check_duplicates(stack))
	{
		stack_free(stack);
		print_error();
	}
	return (stack);
}

t_strategy	parse_strategy(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (strcmp(argv[1], "--simple") == 0)
			return (Simple);
		else if (strcmp(argv[1], "--medium") == 0)
			return (Medium);
		else if (strcmp(argv[1], "--complex") == 0)
			return (Complex);
		else if (strcmp(argv[1], "--adaptive") == 0)
			return (Adaptive);
		i++;
	}
	return (Adaptive);
}

int	is_bench_mode(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (strcmp(argv[i], "--bench") == 0)
			return (1);
		i++;
	}
	return (0);
}
