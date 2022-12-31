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

	highest = get_highest(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	else if ((*stack)->next->next->index == highest)
		sa(stack);
}
