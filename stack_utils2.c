/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:16:34 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:16:37 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_get_at(t_stack *stack, int position)
{
	int		i;
	t_node	*temp;

	i = 0;
	if (!stack || !stack->top || position < 0 || position >= stack->size)
		return (0);
	temp = stack->top;
	while (i < position && temp)
	{
		temp = temp->next;
		i++;
	}
	if (temp)
		return (temp->value);
	return (0);
}

int	stack_get_min(t_stack *stack)
{
	t_node	*temp;
	int		min;

	if (!stack || !stack->top)
		return (INT_MAX);
	temp = stack->top;
	min = temp->value;
	while (temp)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	stack_get_max(t_stack *stack)
{
	t_node	*temp;
	int		max;

	if (!stack || !stack->top)
		return (INT_MAX);
	temp = stack->top;
	max = temp->value;
	while (temp)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	stack_find_position(t_stack *stack, int value)
{
	int		pos;
	t_node	*temp;

	pos = 0;
	if (!stack || !stack->top)
		return (-1);
	temp = stack->top;
	while (temp)
	{
		if (temp->value == value)
			return (pos);
		pos++;
		temp = temp->next;
	}
	return (-1);
}

void	stack_print(t_stack *stack, char *name)
{
	t_node	*temp;

	if (!stack || !name)
		return ;
	if (stack_is_empty(stack))
	{
		ft_printf("(empty)\n");
		return ;
	}
	temp = stack->top;
	while (temp)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}
