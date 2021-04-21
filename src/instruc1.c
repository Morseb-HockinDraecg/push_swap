#include "utils.h"

void	sa(int **stacks)
{
	int	tmp;

	if (stacks[A][0] < 2)
		return ;
	tmp = stacks[A][1];
	stacks[A][1] = stacks[A][2];
	stacks[A][2] = tmp;
}

void	sb(int **stacks)
{
	int	tmp;

	if (stacks[B][0] < 2)
		return ;
	tmp = stacks[B][1];
	stacks[B][1] = stacks[B][2];
	stacks[B][2] = tmp;
}

void	ss(int **stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(int **stacks)
{
	int	i;
	int	len;

	if (!stacks[B][0])
		return ;
	i = -1;
	len = stacks[A][0];
	while (++i < len)
		stacks[A][len + 1 - i] = stacks[A][len - i];
	stacks[A][1] = stacks[B][1];
	stacks[A][0]++;
	len = stacks[B][0];
	i = len;
	while (--i)
		stacks[B][len - i] = stacks[B][len + 1 - i];
	stacks[B][0]--;
}

void	pb(int **stacks)
{
	int	i;
	int	len;

	if (!stacks[A][0])
		return ;
	i = -1;
	len = stacks[B][0];
	while (++i < len)
		stacks[B][len + 1 - i] = stacks[B][len - i];
	stacks[B][1] = stacks[A][1];
	stacks[B][0]++;
	len = stacks[A][0];
	i = len;
	while (--i)
		stacks[A][len - i] = stacks[A][len + 1 - i];
	stacks[A][0]--;
}