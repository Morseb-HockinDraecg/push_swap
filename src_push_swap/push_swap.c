#include "push_swap.h"

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

	stacks = (int **)malloc(sizeof(int *) * 3);
	stacks[A] = cm_error_check(argc, argv);
	stacks[B] = (int *)malloc(sizeof(int) * argc);
	stacks[B][0] = 0;
	if (!stacks[A])
		return (clean_exit(stacks, 1));
	stacks[A] = sub_nbr(stacks);
	if (!is_sort(stacks))
		return (clean_exit(stacks, 0));
	if (stacks[A][0] == 2)
		two_nbrs(stacks);
	else if (stacks[A][0] == 3)
		three_nbrs(stacks);
	else
		algo(stacks);
	return (clean_exit(stacks, 0));
}
