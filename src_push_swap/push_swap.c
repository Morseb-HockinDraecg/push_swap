#include "push_swap.h"

void	write_stacks(int **stacks)
{
	int	i;

	i = 0;
	while (i < stacks[A][0] && i < stacks[B][0])
	{
		++i;
		ft_putnbr(stacks[A][i]);
		write(1, "\t", 1);
		ft_putnbr(stacks[B][i]);
		write(1, "\n", 1);
	}
	while (i < stacks[A][0])
	{
		ft_putnbr(stacks[A][++i]);
		write(1, "\n", 1);
	}
	while (i < stacks[B][0])
	{
		write(1, "\t", 1);
		ft_putnbr(stacks[B][++i]);
		write(1, "\n", 1);
	}
	printf("_\t_\nA\tB\n");
}

static int	clean_exit(int **stacks, int ret)
{
	free(stacks[A]);
	free(stacks[B]);
	free(stacks);
	return (ret);
}

int	main(int argc, char **argv)
{
	int	**stacks;

	stacks = (int **)malloc(sizeof(int *) * 2);
	stacks[A] = cm_error_check(argc, argv);
	stacks[B] = (int *)malloc(sizeof(int) * argc);
	stacks[B][0] = 0;
	if (!stacks[A])
	{
		write(STDERR_FILENO, "Error\n", cm_strlen("Error\n"));
		return (clean_exit(stacks, 1));
	}
	stacks[A] = sub_nbr(stacks);
	write_stacks(stacks);
	if (is_sort(stacks))
		return (clean_exit(stacks, 0));
	if (stacks[A][0] == 2)
		two_nbrs(stacks);
	else if (stacks[A][0] == 3)
		three_nbrs(stacks);
	else
		;
	if (is_sort(stacks))
		return (clean_exit(stacks, 0));
	return (0);
}
