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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(1);
	(void)stack_b;
	stack_a = NULL;
	if (!input_check(argv))
		error(NULL, NULL);
	initialize_stack(argv, &stack_a);
	if (DEBUG)
		print_stack(stack_a);
	free_stack(&stack_a);
}
