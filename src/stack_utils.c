#include "push_swap.h"

int	get_stack_length(t_stack *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

t_stack	*get_stack_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
