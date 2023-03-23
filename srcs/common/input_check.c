/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:16:11 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 12:16:12 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	check_doubles(char **argv, int nb, int i)
{
	while (argv[i])
	{
		if (ft_atol(argv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

int	input_check(char **argv)
{
	int		i;
	long	nb;

	i = 1;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		if (!(is_int(argv[i])) || nb > INT_MAX || nb < INT_MIN || \
		check_doubles(argv, nb, i + 1))
			return (0);
		i++;
	}
	return (1);
}
