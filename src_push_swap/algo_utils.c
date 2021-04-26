#include "push_swap.h"

static void	copy_instru(int **stacks, int new_elem)
{
	int	*tmp;
	int	i;

	if (new_elem == -1)
		return ;
	tmp = (int *)malloc(sizeof(int) * (stacks[INSTRU][0] + 1 + new_elem));
	tmp[0] = stacks[INSTRU][0] + 1;
	tmp[tmp[0]] = new_elem;
	i = 0;
	while (i++ < stacks[INSTRU][0])
		tmp[i] = stacks[INSTRU][i];
	free(stacks[INSTRU]);
	stacks[INSTRU] = NULL;
	stacks[INSTRU] = tmp;
}

void	up_to_b(int **stacks, int to_top)
{
	while (to_top--)
		copy_instru(stacks, ra);
}

void	bottom_to_b(int **stacks, int to_top)
{
	while (to_top--)
		copy_instru(stacks, rra);
}

void	sort_b(int **stacks, int next_nb_to_place)
{
	if (to_rsort(stacks, next_nb_to_place))
		copy_instru(stacks, rrb);
	(void)stacks;
}
