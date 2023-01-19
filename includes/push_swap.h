#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

/* SORTING FUNCTION*/

void	tiny_sort(t_stack **stack);
void	big_sort(t_stack **stack_a, t_stack **stack_b);

/* POSITIONS & COST*/

void	fill_stack_position(t_stack *stack);
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest(t_stack **stack_a, t_stack **stack_b);
void	stack_target_position(t_stack **stack_a, t_stack **stack_b);

#endif
