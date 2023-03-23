/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:15:55 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 12:15:57 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	assign_index(t_stack *stack, int stack_length)
{
	t_stack	*tmp;
	t_stack	*highest;
	int		value;

	while (--stack_length)
	{
	tmp = stack;
	highest = NULL;
	value = INT_MIN;
		while (tmp)
		{
			if (tmp->value > value && tmp->index == 0)
			{
				value = tmp->value;
				highest = tmp;
				tmp = stack;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = stack_length;
	}
}

void	initialize_stack(char **argv, t_stack **stack)
{
	int	i;

	i = 1;
	while (argv[i])
		stack_add_back(stack, create_stack(ft_atol(argv[i++])));
	assign_index(*stack, get_stack_length(*stack));
}
