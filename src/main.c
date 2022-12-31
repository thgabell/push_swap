#include "push_swap.h"

static void	print_stack(t_stack *stack)
{
	t_stack	*length;

	length = stack;
	while (stack)
	{
		printf("value: %d | index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
	printf("stack_length: %d", get_stack_length(length));
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_length;

	(void)stack_b;
	stack_length = get_stack_length(*stack_a);
	if (stack_length == 2 && !(is_sorted(*stack_a)))
		sa(stack_a);
	else if (stack_length == 3 && !(is_sorted(*stack_a)))
		tiny_sort(stack_a);
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
	if (DEBUG)
		print_stack(stack_a);
	free_stack(&stack_a);
}
