#include "push_swap.h"

int	is_sort(int **stacks)
{
	int	len;
	int	i;

	len = stacks[A][0];
	i = 0;
	if (stacks[B][0] > 0)
		return (1);
	while (++i < len)
		if (stacks[A][i] > stacks[A][i + 1])
			return (1);
	return (0);
}

static int	to_rsort_algo(int **stacks, int len, int nb, int i)
{
	int	compare[2];

	compare[1] = INT_MAX;
	if (stacks[B][len] == 0)
		compare[0] = (unsigned)(compare[1] - stacks[B][1]);
	else
		compare[0] = (unsigned)(stacks[B][len] - stacks[B][1]);
	if (stacks[B][0] - stacks[B][1] < compare[0])
		nb--;
	while (++i < len)
	{
		if (stacks[B][i - 1] == 0)
			compare[0] = (unsigned)(compare[1] - stacks[B][i + 1]);
		else
			compare[0] = (unsigned)(stacks[B][i - 1] - stacks[B][i + 1]);
		if (stacks[B][i] - stacks[B][i + 1] < compare[0])
			nb--;
	}
	if (stacks[B][i - 1] == 0)
		compare[0] = (unsigned)(compare[1] - stacks[B][0]);
	else
		compare[0] = (unsigned)(stacks[B][i - 1] - stacks[B][0]);
	if (stacks[B][i] - stacks[B][0] < compare[0])
		nb--;
	return (nb);
}

int	to_rsort(int **stacks, int next_nb_to_place)
{
	int	len;
	int	ret;

	len = stacks[B][0];
	stacks[B][0] = next_nb_to_place;
	ret = to_rsort_algo(stacks, len, len, 0);
	stacks[B][0] = len;
	if (!ret)
		return (1);
	return (0);
}

void	fill_substitute(int **substitute, int **stack, int len)
{
	int	fill[2];
	int	min[2];

	min[0] = INT_MAX - 1;
	fill[0] = 0;
	while (fill[0]++ < len)
	{
		if (min[0] > stack[A][fill[0]])
			min[0] = stack[A][fill[0]];
	}
	fill[0] = 0;
	min[1] = INT_MAX;
	while (fill[0]++ < len)
	{
		fill[1] = 0;
		while (fill[1]++ < len)
		{
			if (min[1] > stack[A][fill[1]] && stack[A][fill[1]] > min[0])
				min[1] = stack[A][fill[1]];
			if (min[0] == stack[A][fill[1]])
				(*substitute)[fill[1]] = fill[0] - 1;
		}
		min[0] = min[1];
		min[1] = INT_MAX;
	}
}

int	*sub_nbr(int **stack)
{
	int	*substitute;
	int	len;

	len = *stack[A];
	substitute = (int *)malloc(sizeof(int) * (len + 1));
	substitute[0] = len;
	fill_substitute(&substitute, stack, len);
	free(stack[A]);
	return (substitute);
}
