#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

# define DEBUG 0

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

/* INPUT CHECK */

int		input_check(char **argv);

/* SORTING FUNCTION*/

void	tiny_sort(t_stack **stack);

/* STACK FUNCTION */

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
t_stack	*create_stack(int value);
void	free_stack(t_stack **stack);
t_stack	*get_stack_last(t_stack *stack);
int		get_stack_length(t_stack *stack);
t_stack	*get_stack_before_last(t_stack *stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	stack_add_back(t_stack **stack, t_stack *new);
void	initialize_stack(char **argv, t_stack **stack_a);

/* UTILS FUNCTION */

int		is_digit(char c);
int		is_int(char *nb);
int		is_sorted(t_stack *stack);
long	ft_atol(const char *nptr);
void	error(t_stack **stack_a, t_stack **stack_b);

#endif
