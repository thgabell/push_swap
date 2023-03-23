/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:17:04 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 14:12:38 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_length;

	(void)stack_b;
	stack_length = get_stack_length(*stack_a);
	if (stack_length == 2 && !(is_sorted(*stack_a)))
	{
		sa(stack_a);
		write(1, "sa\n", 3);
	}
	else if (stack_length == 3)
		tiny_sort(stack_a);
	else if (stack_length > 3 && !(is_sorted(*stack_a)))
		big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	if (!input_check(argv))
		error(NULL, NULL);
	initialize_stack(argv, &stack_a);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
