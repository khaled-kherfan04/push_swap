/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdalal <amdalal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:31:54 by amdalal           #+#    #+#             */
/*   Updated: 2026/01/08 18:15:12 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int max)
{
	int	bits;

	bits = 0;
	while (max != 0)
	{
		max = max / 2;
		bits++;
	}
	return (bits);
}

static int	get_bit(int num, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		num = num / 2;
		i++;
	}
	if (num % 2 == 0)
		return (0);
	return (1);
}

void	sort_complex(t_stack *a, t_stack *b, t_opcounts *ops)
{
	int	max_bits;
	int	max_index;
	int	i;
	int	j;
	int	size;

	if (!a || !b)
		return ;
	assign_indices(a);
	size = stack_size(a);
	max_index = size - 1;
	max_bits = count_bits(max_index);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (get_bit(a->top->index, i) == 0)
				pb(a, b, ops);
			else
				ra(a, ops);
			j++;
		}
		while (!stack_is_empty(b))
			pa(a, b, ops);
		i++;
	}
}
