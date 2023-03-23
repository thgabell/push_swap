/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:16:26 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 12:16:27 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	get_stack_length(t_stack *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

int	get_stack_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_stack_min_index_pos(t_stack	*stack)
{
	int	min;
	int	pos;

	min = stack->index;
	pos = stack->pos;
	while (stack)
	{
		if (min > stack->index)
		{
			min = stack->index;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}

t_stack	*get_stack_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
