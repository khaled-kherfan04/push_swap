/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:54:47 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 17:54:51 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_benchmark(t_opcounts *ops, double disorder, t_strategy strategy)
{
	if (!ops)
		return ;
	ft_printf("[bench] disorder: %d\n", disorder * 100);
	ft_printf("[bench] strategy: %s / %s\n", get_strategy_name(strategy),
		get_complexity_string(strategy));
	ft_printf("[bench] total_ops: %d\n", ops->total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", ops->sa, ops->sb,
		ops->ss, ops->pa, ops->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", ops->ra,
		ops->rb, ops->rr, ops->rra, ops->rrb, ops->rrr);
}

char	*get_strategy_name(t_strategy strategy)
{
	if (strategy == Simple)
		return ("Simple");
	else if (strategy == Medium)
		return ("Medium");
	else if (strategy == Complex)
		return ("Complex");
	else if (strategy == Adaptive)
		return ("Adaptive");
	return ("Adaptive");
}

char	*get_complexity_string(t_strategy strategy)
{
	if (strategy == Simple)
		return ("O(n²)");
	else if (strategy == Medium)
		return ("O(n√n)");
	else if (strategy == Complex)
		return ("O(n log n)");
	else if (strategy == Adaptive)
		return ("Adaptive");
	return ("Adaptive");
}
