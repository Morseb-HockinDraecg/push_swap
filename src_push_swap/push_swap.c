#include "push_swap.h"

static void	write_stacks(int **stacks)
{
	int	i;

	i = 0;
	// printf("%d\t%d\n", stacks[A][0], stacks[B][0]);
	// printf("-\t-\n");
	while (i < stacks[0][0] && i < stacks[1][0])
	{
		++i;
		ft_putnbr(stacks[0][i]);
		write(1, "\t", 1);
		ft_putnbr(stacks[1][i]);
		write(1, "\n", 1);
	}
	while (i < stacks[0][0])
	{
		ft_putnbr(stacks[0][++i]);
		write(1, "\n", 1);
	}
	while (i < stacks[1][0])
	{
		write(1, "\t", 1);
		ft_putnbr(stacks[1][++i]);
		write(1, "\n", 1);
	}
	printf("_\t_\nA\tB\n");
}

int	main(int argc, char **argv)
{
	int	**stacks;
	int	*stack[2];

	stack[A] = cm_error_check(argc, argv);
	if (!stack[A])
		return (1);
	stacks = (int **)malloc(sizeof(int *) * 2);
	stack[B] = (int *)malloc(sizeof(int) * argc);
	stacks[A] = stack[A];
	stacks[B] = stack[B];
	stack[B][0] = 0;
	if (is_sort(stacks))
		return (0);
	if (stacks[A][0] == 2)
		two_nbrs(stacks);
	else if (stacks[A][0] == 3)
		three_nbrs(stacks);
	else
		;
	if (is_sort(stacks))
		return (0);
	write_stacks(stacks);
	return (0);
}
