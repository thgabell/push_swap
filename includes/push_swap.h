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

int		nput_check(char **argv);

/* STACK FUNCTION */

t_stack	*create_stack(int value);
void	free_stack(t_stack **stack);
int		get_stack_length(t_stack *stack);
t_stack	*get_stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	initialize_stack(char **argv, t_stack **stack_a);

/* UTILS FUNCTION */

int		is_digit(char c);
int		is_int(char *nb);
long	ft_atol(const char *nptr);
void	error(t_stack **stack_a, t_stack **stack_b);

#endif
