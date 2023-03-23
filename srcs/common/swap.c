/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:16:18 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 14:10:00 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	sa(t_stack **stack_a)
{
	if (*stack_a)
		swap(*stack_a);
}

void	sb(t_stack **stack_b)
{
	if (*stack_b)
		swap(*stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		swap(*stack_a);
		swap(*stack_b);
	}	
}
