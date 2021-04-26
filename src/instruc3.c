#include "utils.h"

void	frra(int **stacks)
{
	int	i;
	int	tmp;
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

void	frrb(int **stacks)
{
	int	i;
	int	tmp;
	int	len;

dprintf(2, "=>coucou<=\n");
	if (stacks[B][0] < 2)
		return ;
	len = stacks[B][0];
	tmp = stacks[B][len];
	i = -1;
	while (++i < len)
		stacks[B][len - i] = stacks[B][len - 1 - i];
	stacks[B][1] = tmp;
}

void	frrr(int **stacks)
{
	frra(stacks);
	frrb(stacks);
}
