/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:54:12 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:12:45 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	int	chunk_size;

	if (size <= 0)
		return (1);
	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	if (chunk_size <= 100)
		return (chunk_size);
	else if (chunk_size <= 500)
		return (chunk_size + chunk_size / 2);
	else
		return (chunk_size * 2);
}

void	assign_indices(t_stack *a)
{
	t_node	*curr;
	t_node	*cmp;
	int		index;

	if (!a)
		return ;
	curr = a->top;
	while (curr)
	{
		index = 0;
		cmp = a->top;
		while (cmp)
		{
			if (cmp->value < curr->value)
				index++;
			cmp = cmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

void	push_back_sorted(t_stack *a, t_stack *b, t_opcounts *ops)
{
	int	max;
	int	max_pos;
	int	size;

	while (!stack_is_empty(b))
	{
		max = stack_get_max(b);
		max_pos = stack_find_position(b, max);
		size = stack_size(b);
		if (max_pos <= size / 2)
			while (max_pos-- > 0)
				rb(b, ops);
		else
			while (max_pos++ < size)
				rrb(b, ops);
		pa(a, b, ops);
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_opcounts *ops)
{
	int	chunk_size;
	int	range;
	int	i;

	if (!a || !b || a->size <= 5)
	{
		sort_simple(a, b, ops);
		return ;
	}
	assign_indices(a);
	chunk_size = get_chunk_size(a->size);
	range = chunk_size;
	while (!stack_is_empty(a))
	{
		i = 0;
		while (i < stack_size(a))
		{
			if (a->top->index < range)
			{
				pb(a, b, ops);
				range++;
			}
			else
				ra(a, ops);
			i++;
		}
	}
	push_back_sorted(a, b, ops);
}
