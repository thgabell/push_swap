#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_last(*stack);
	before_tail = get_stack_before_last(*stack);
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
	before_tail->next = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
