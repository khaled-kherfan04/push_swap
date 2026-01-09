/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:04:52 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:06:46 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_opcounts *ops)
{
	int	temp;

	if (!a || !a->top || !a->top->next)
		return ;
	temp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = temp;
	if (ops)
	{
		ops->total++;
		ops->sa++;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b, t_opcounts *ops)
{
	int	temp;

	if (!b || !b->top || !b->top->next)
		return ;
	temp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = temp;
	if (ops)
	{
		ops->total++;
		ops->sb++;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, t_opcounts *ops)
{
	int	first;
	int	second;

	if (a && a->size > 1)
	{
		first = stack_pop(a);
		second = stack_pop(a);
		stack_push(a, second);
		stack_push(a, first);
	}
	if (b && b->size > 1)
	{
		first = stack_pop(b);
		second = stack_pop(b);
		stack_push(b, second);
		stack_push(b, first);
	}
	if (ops)
	{
		ops->ss++;
		ops->total++;
	}
	ft_printf("ss\n");
}
