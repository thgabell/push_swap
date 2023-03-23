/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:16:56 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 12:16:56 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ra(stack_a);
			write(1, "ra\n", 3);
			(*cost_a)--;
		}
		else
		{
			rra(stack_a);
			write(1, "rra\n", 4);
			(*cost_a)++;
		}
	}
}

static void	rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rb(stack_b);
			write(1, "rb\n", 3);
			(*cost_b)--;
		}
		else
		{
			rrb(stack_b);
			write(1, "rrb\n", 4);
			(*cost_b)++;
		}	
	}
}

static void	exec(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			rr(stack_a, stack_b);
			write(1, "rr\n", 3);
			cost_a--;
			cost_b--;
		}
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			rrr(stack_a, stack_b);
			write(1, "rrr\n", 4);
			cost_a++;
			cost_b++;
		}
	}
	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	do_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest_total_cost;
	int		cheapest_cost_a;
	int		cheapest_cost_b;
	t_stack	*tmp;

	tmp = *stack_b;
	cheapest_total_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
	cheapest_cost_a = tmp->cost_a;
	cheapest_cost_b = tmp->cost_b;
	while (tmp)
	{
		if (ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a) < cheapest_total_cost)
		{
			cheapest_total_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cheapest_cost_a = tmp->cost_a;
			cheapest_cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	exec(stack_a, stack_b, cheapest_cost_a, cheapest_cost_b);
}

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*tmp;

	tmp = *stack_b;
	size_a = get_stack_length(*stack_a);
	size_b = get_stack_length(*stack_b);
	while (tmp)
	{
		tmp->cost_b = tmp->pos;
		if (tmp->pos > size_b / 2)
			tmp->cost_b = (size_b - tmp->pos) * -1;
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > size_a / 2)
			tmp->cost_a = (size_a - tmp->target_pos) * -1;
		tmp = tmp->next;
	}
}
