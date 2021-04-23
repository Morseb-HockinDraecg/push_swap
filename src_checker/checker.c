#include "checker.h"

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

int	main(int argc, char **argv)
{
	int		**stacks;
	t_list	*lst_cmd;

	lst_cmd = NULL;
	take_stdin(&lst_cmd);
	stacks = (int **)malloc(sizeof(int *) * 2);
	stacks[A] = cm_error_check(argc, argv);
	stacks[B] = (int *)malloc(sizeof(int) * argc);
	stacks[B][0] = 0;
	if (!stacks[A])
		return (clean_exit(stacks, &lst_cmd, 2));
	if (argc == 1)
		return (clean_exit(stacks, &lst_cmd, 0));
	exec_instruc(lst_cmd, stacks);
	// write_stacks(stacks);
	if (check_order(stacks))
		return (clean_exit(stacks, &lst_cmd, 1));
	return (clean_exit(stacks, &lst_cmd, 0));
}
