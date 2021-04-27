#include "push_swap.h"

static void	copy_instru(int **stacks, int new_elem)
{
	int	*tmp;
	int	i;

	if (new_elem == -1)
		return ;
	tmp = (int *)malloc(sizeof(int) * (stacks[INSTRU][0] + 2));
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
	if (stacks[B][0] < 2)
	{
		copy_instru(stacks, pb);
		return ;
	}
	if (to_rsort(stacks, next_nb_to_place))
	{
		dprintf(2, "Coucou\n");
		if (next_nb_to_place > stacks[B][1])
			copy_instru(stacks, rrb);
		else
			copy_instru(stacks, rb);
	}
	copy_instru(stacks, pb);
}

void	clean_b(int **stacks)
{
	int	len;

	len = stacks[B][0];
	stacks[INSTRU] = (int *)malloc(sizeof(int) * 1);
	stacks[INSTRU][0] = 0;
	while (len--)
		copy_instru(stacks, pa);
	send_instruc(stacks);
}
