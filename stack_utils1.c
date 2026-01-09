/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:32:15 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:17:49 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->top = NULL;
	new->size = 0;
	return (new);
}

void	stack_push(t_stack *stack, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	if (!stack)
		return ;
	new->value = value;
	new->index = 0;
	new->next = stack->top;
	new->prev = NULL;
	if (stack->top)
		stack->top->prev = new;
	stack->top = new;
	stack->size++;
}

int	stack_pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack || !stack->top)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	if (!stack->top)
		stack->top->prev = NULL;
	free(temp);
	stack->size--;
	return (value);
}

int	stack_peek(t_stack *stack)
{
	if (!stack || !stack->top)
		return (0);
	return (stack->top->value);
}

void	stack_free(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
