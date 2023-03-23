/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:16:28 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 14:07:57 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_last(*stack);
	temp->next = NULL;
	tail->next = temp;
}

void	ra(t_stack **stack_a)
{
	if (*stack_a)
		rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	if (*stack_b)
		rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}
