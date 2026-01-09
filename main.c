/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:59:41 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 17:59:43 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_opcounts(t_opcounts *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->total = 0;
}

void	execute_sort(t_stack *a, t_stack *b, t_opcounts *ops,
		t_strategy strategy)
{
	if (strategy == Simple)
		sort_simple(a, b, ops);
	else if (strategy == Medium)
		sort_medium(a, b, ops);
	else if (strategy == Complex)
		sort_complex(a, b, ops);
	else
		sort_adaptive(a, b, ops);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_opcounts	ops;
	t_strategy	strategy;
	int			bench_mode;
	double		disorder;

	a = parse_arg(argc, argv);
	b = stack_new();
	if (!a || stack_is_sorted(a))
	{
		stack_free(a);
		return (0);
	}
	if (!b)
	{
		print_error();
		stack_free(a);
	}
	init_opcounts(&ops);
	strategy = parse_strategy(argc, argv);
	bench_mode = is_bench_mode(argc, argv);
	disorder = compute_disorder(a);
	execute_sort(a, b, &ops, strategy);
	if (bench_mode)
		print_benchmark(&ops, disorder, strategy);
	stack_free(a);
	stack_free(b);
}
