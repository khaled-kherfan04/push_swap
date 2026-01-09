/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:55:05 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:24:05 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// compute disorder metric (0.0 to 1.0)
double	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_node	*node_i;
	t_node	*node_j;
	int		i;
	int		j;

	if (!stack || !stack->top || stack->size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	node_i = stack->top;
	i = 0;
	while (i < stack->size - 1)
	{
		node_j = node_i->next;
		j = i + 1;
		while (j < stack->size)
		{
			total_pairs++;
			if (node_i->value > node_j->value)
				mistakes++;
			node_j = node_j->next;
			j++;
		}
		node_i = node_i->next;
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

// git disorder category string
char	*get_disorder_category(double disorder)
{
	if (disorder < 0.2)
		return ("Low disorder (almost sorted)");
	else if (disorder < 0.5)
		return ("Medium disorder");
	else
		return ("High disorder");
}

// print disorder information
//%s incorrect
void	print_disorder_info(t_stack *stack)
{
	double	disorder;

	if (!stack)
		return ;
	disorder = compute_disorder(stack);
	ft_printf("[info] Disorder:%d - %s\n", disorder * 100,
		get_disorder_category(disorder));
}
