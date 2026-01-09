/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:01:07 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:01:58 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_opcounts *ops)
{
	t_node	*first;
	t_node	*last;

	if (!a || !a->top || a->top->next)
		return ;
	first = a->top;
	a->top = first->next;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (ops)
	{
		ops->total++;
		ops->ra++;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack *b, t_opcounts *ops)
{
	t_node	*first;
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	b->top = first->next;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (ops)
	{
		ops->total++;
		ops->rb++;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, t_opcounts *ops)
{
	t_node	*first;
	t_node	*last;

	if (a && stack_size(a) >= 2)
	{
		first = a->top;
		a->top = first->next;
		last = a->top;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
	if (b && stack_size(b) >= 2)
	{
		first = b->top;
		b->top = first->next;
		last = b->top;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
	if (ops)
	{
		ops->total++;
		ops->rr++;
	}
	write(1, "rr\n", 3);
}

void	rra(t_stack *a, t_opcounts *ops)
{
	t_node	*last;
	t_node	*second_last;

	if (!a || !a->top || !a->top->next)
		return ;
	last = a->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = a->top;
	a->top = last;
	if (ops)
	{
		ops->total++;
		ops->rra++;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b, t_opcounts *ops)
{
	t_node	*last;
	t_node	*second_last;

	if (!b || !b->top || !b->top->next)
		return ;
	last = b->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = b->top;
	b->top = last;
	if (ops)
	{
		ops->total++;
		ops->rrb++;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, t_opcounts *ops)
{
	t_node	*last;
	t_node	*second_last;

	if (a && stack_size(a) >= 2)
	{
		second_last = NULL;
		last = a->top;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = a->top;
		a->top = last;
	}
	if (b && stack_size(b) >= 2)
	{
		second_last = NULL;
		last = b->top;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = b->top;
		b->top = last;
	}
	if (ops)
	{
		ops->total++;
		ops->rrr++;
	}
	write(1, "rrr\n", 4);
}
