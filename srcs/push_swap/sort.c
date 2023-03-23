/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:17:07 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 12:17:07 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest(t_stack *stack)
{
	int	highest;

	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

void	tiny_sort(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = get_highest(*stack);
	if ((*stack)->index == highest)
	{
		ra(stack);
		write(1, "ra\n", 3);
	}
	else if ((*stack)->next->index == highest)
	{
		rra(stack);
		write(1, "rra\n", 4);
	}
	if ((*stack)->index > (*stack)->next->index)
	{
		sa(stack);
		write(1, "sa\n", 3);
	}
}

static void	final_rotate(t_stack **stack_a)
{
	int	min_index_pos;

	fill_stack_position(*stack_a);
	min_index_pos = get_stack_min_index_pos(*stack_a);
	if (min_index_pos < get_stack_length(*stack_a) / 2)
	{
		while (min_index_pos--)
		{
			ra(stack_a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (min_index_pos++ < get_stack_length(*stack_a))
		{
			rra(stack_a);
			write(1, "rra\n", 4);
		}
	}
}

static void	pb_all_expect_3(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	size;

	i = 0;
	size = get_stack_length(*stack_a);
	while (size > 4 && i < size - 3 && i < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			write(1, "pb\n", 3);
			i++;
		}
		else
		{
			ra(stack_a);
			write(1, "ra\n", 3);
		}
	}
	while (i < size - 3)
	{
		pb(stack_a, stack_b);
		write(1, "pb\n", 3);
		i++;
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	pb_all_expect_3(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		stack_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest(stack_a, stack_b);
	}
	if (!(is_sorted(*stack_a)))
		final_rotate(stack_a);
}
