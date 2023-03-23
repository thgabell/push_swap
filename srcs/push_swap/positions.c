/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:17:09 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 12:17:09 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_position(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

static int	get_target_position(t_stack *stack_a, int index)
{
	int	target_pos;
	int	target_index;

	if (index < get_stack_max_index(stack_a))
	{
		target_index = get_stack_max_index(stack_a);
		while (stack_a)
		{
			if (index < stack_a->index && stack_a->index <= target_index)
			{
				target_pos = stack_a->pos;
				target_index = stack_a->index;
			}
			stack_a = stack_a->next;
		}
	}
	else
		target_pos = get_stack_min_index_pos(stack_a);
	return (target_pos);
}

void	stack_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	fill_stack_position(*stack_a);
	fill_stack_position(*stack_b);
	while (tmp)
	{
		tmp->target_pos = get_target_position(*stack_a, tmp->index);
		tmp = tmp->next;
	}
}
