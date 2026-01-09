/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdalal <amdalal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:30:49 by amdalal           #+#    #+#             */
/*   Updated: 2026/01/08 18:14:15 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack *a, t_stack *b, t_opcounts *ops)
{
	int	min_pos;
	int	size;

	if (!a || !b || stack_is_empty(a))
		return ;
	min_pos = stack_get_min(a);
	min_pos = stack_find_position(a, min_pos);
	size = stack_size(a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a, ops);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a, ops);
			min_pos++;
		}
	}
	pb(a, b, ops);
}

void	sort_three(t_stack *a, t_opcounts *ops)
{
	int	first;
	int	second;
	int	third;

	first = stack_get_at(a, 0);
	second = stack_get_at(a, 1);
	third = stack_get_at(a, 2);
	if (first > second && second < third && first < third)
		sa(a, ops);
	else if (first > second && second > third)
	{
		sa(a, ops);
		rra(a, ops);
	}
	else if (first > second && second < third && first > third)
		ra(a, ops);
	else if (first < second && second > third && first < third)
	{
		sa(a, ops);
		ra(a, ops);
	}
	else if (first < second && second > third && first > third)
		rra(a, ops);
}

void	sort_five(t_stack *a, t_stack *b, t_opcounts *ops)
{
	push_min_to_b(a, b, ops);
	push_min_to_b(a, b, ops);
	sort_three(a, ops);
	pa(a, b, ops);
	pa(a, b, ops);
}

void	sort_simple(t_stack *a, t_stack *b, t_opcounts *ops)
{
	if (!a || !b)
		return ;
	if (a->size <= 1 || stack_is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (stack_get_at(a, 0) > stack_get_at(a, 1))
			sa(a, ops);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a, ops);
		return ;
	}
	if (a->size == 5)
	{
		sort_five(a, b, ops);
		return ;
	}
	while (!stack_is_empty(a))
		push_min_to_b(a, b, ops);
	while (!stack_is_empty(b))
		pa(a, b, ops);
}
