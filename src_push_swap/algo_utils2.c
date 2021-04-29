#include "push_swap.h"

void	top_to_b(int **stacks, int to_top)
{
	if (to_top == 2)
		copy_instru(stacks, sa);
	else
	{
		while (--to_top)
			copy_instru(stacks, ra);
	}
}

void	bottom_to_b(int **stacks, int to_top)
{
	copy_instru(stacks, rra);
	if (to_top)
	{
		while (to_top--)
			copy_instru(stacks, rra);
	}
}

void	clean_b_normy(int **stacks, int len, int *rang)
{
	int	i;

	i = 0;
	while (i++ < len)
	{
		if (stacks[B][i] == (len -1))
		{
			*rang = i;
			break ;
		}
	}
}
