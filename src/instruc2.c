#include "utils.h"

void	fra(int **stacks)
{
	int	i;
	int	tmp;
	int	len;

	if (stacks[A][0] < 2)
		return ;
	tmp = stacks[A][1];
	len = stacks[A][0];
	i = len;
	while (--i)
		stacks[A][len - i] = stacks[A][len + 1 - i];
	stacks[A][len] = tmp;
}

void	frb(int **stacks)
{
	int	i;
	int	tmp;
	int	len;

	if (stacks[B][0] < 2)
		return ;
	tmp = stacks[B][1];
	len = stacks[B][0];
	i = len;
	while (--i)
		stacks[B][len - i] = stacks[B][len + 1 - i];
	stacks[B][len] = tmp;
}

void	frr(int **stacks)
{
	fra(stacks);
	frb(stacks);
}
