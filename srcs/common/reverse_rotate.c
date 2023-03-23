/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:16:30 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 14:06:53 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_last(*stack);
	before_tail = get_stack_before_last(*stack);
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
	before_tail->next = NULL;
}

void	rra(t_stack **stack_a)
{
	if (*stack_a)
		reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	if (*stack_b)
		reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && *stack_b)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}
