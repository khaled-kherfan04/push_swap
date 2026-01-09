/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdalal <amdalal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:32:29 by amdalal           #+#    #+#             */
/*   Updated: 2026/01/08 18:11:21 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_strategy(t_stack *a, t_stack *b, t_opcounts *ops,
		double disorder)
{
	int	size;

	if (!a || !b)
		return ;
	size = stack_size(a);
	if (size <= 5)
		sort_simple(a, b, ops);
	else if (disorder < 0.2)
		sort_simple(a, b, ops);
	else if (disorder < 0.5)
		sort_medium(a, b, ops);
	else
		sort_complex(a, b, ops);
}

void	sort_adaptive(t_stack *a, t_stack *b, t_opcounts *ops)
{
	double	disorder;

	if (!a || !b)
		return ;
	if (stack_is_sorted(a))
		return ;
	disorder = compute_disorder(a);
	select_strategy(a, b, ops, disorder);
}
