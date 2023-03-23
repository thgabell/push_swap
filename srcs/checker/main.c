/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:15:43 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 12:15:43 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	checker(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 'r' && line[1] == 'a')
		ra(stack_a);
	else if (line[0] == 'r' && line[1] == 'b')
		rb(stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(stack_a, stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(stack_a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		rrr(stack_a, stack_b);
	else if (line[0] == 'p' && line[1] == 'a')
		pa(stack_a, stack_b);
	else if (line[0] == 'p' && line[1] == 'b')
		pb(stack_a, stack_b);
	else if (line[0] == 's' && line[1] == 'a')
		sa(stack_a);
	else if (line[0] == 's' && line[1] == 'b')
		sb(stack_b);
	else
		error(stack_a, stack_a);
}

static void	get_instruction(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		checker(stack_a, stack_b, line);
		free(line);
	}
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
	get_instruction(&stack_a, &stack_b);
	if (!stack_b && is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
