/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:17:11 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:24:38 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_empty(t_stack *stack)
{
	if (!stack || !stack->top || stack->size == 0)
		return (1);
	return (0);
}

int	stack_is_sorted(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->top)
		return (1);
	temp = stack->top;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}
