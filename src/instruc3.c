#include "utils.h"

void	rra(int **stacks)
{
	int	i;
	int tmp;
	int	len;

	if (stacks[A][0] < 2)
		return ;
	len = stacks[A][0];
	tmp = stacks[A][len];
	i = -1;
	while (++i < len)
		stacks[A][len - i] = stacks[A][len - 1 - i];
	stacks[A][1] = tmp;
}

void	rrb(int **stacks)
{
	int	i;
	int tmp;
	int	len;

	if (stacks[B][0] < 2)
		return ;
	len = stacks[B][0];
	tmp = stacks[B][len];
	i = -1;
	while (++i < len)
		stacks[B][len - i] = stacks[B][len - 1 - i];
	stacks[B][1] = tmp;
}

void	rrr(int **stacks)
{
	rra(stacks);
	rrb(stacks);
}

