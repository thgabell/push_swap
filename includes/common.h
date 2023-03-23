/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:17:57 by thgabell          #+#    #+#             */
/*   Updated: 2023/03/14 12:17:57 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/*INPUT CHECK*/

int		input_check(char **argv);

/*STACK FUNCTIONS*/
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
t_stack	*create_stack(int value);
void	free_stack(t_stack **stack);
t_stack	*get_stack_last(t_stack *stack);
int		get_stack_length(t_stack *stack);
int		get_stack_max_index(t_stack *stack);
t_stack	*get_stack_before_last(t_stack *stack);
int		get_stack_min_index_pos(t_stack	*stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	initialize_stack(char **argv, t_stack **stack_a);

/*UTILS*/

int		ft_abs(int nb);
int		is_digit(char c);
int		is_int(char *nb);
int		is_sorted(t_stack *stack);
long	ft_atol(const char *nptr);
void	error(t_stack **stack_a, t_stack **stack_b);

#endif