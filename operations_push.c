/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:00:09 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:00:53 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, t_opcounts *ops)
{
	t_node	*temp;

	if (!b || !b->top)
		return ;
	temp = b->top;
	b->top = temp->next;
	b->size--;
	temp->next = a->top;
	a->top = temp;
	a->size++;
	if (ops)
	{
		ops->total++;
		ops->pa++;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, t_opcounts *ops)
{
	t_node	*temp;

	if (!a || !a->top)
		return ;
	temp = a->top;
	a->top = temp->next;
	a->size--;
	temp->next = b->top;
	b->top = temp;
	b->size++;
	if (ops)
	{
		ops->total++;
		ops->pb++;
	}
	write(1, "pb\n", 3);
}
