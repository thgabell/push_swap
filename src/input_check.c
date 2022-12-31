#include "push_swap.h"

static int	check_doubles(char **argv, int nb, int i)
{
	while (argv[i])
	{
		if (ft_atol(argv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

int	nput_check(char **argv)
{
	int		i;
	long	nb;

	i = 1;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		if (!(is_int(argv[i])) || nb > INT_MAX || nb < INT_MIN || \
		check_doubles(argv, nb, i + 1))
			return (0);
		i++;
	}
	return (1);
}
