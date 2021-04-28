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

static int	to_rsort_algo(int **stacks, int len, int min, int max)
{
	int	i;
	int	*s;
	int	above;
	int	below;

	s = stacks[B];
	i = -1;
	while (i++ < len)
	{
		if (i == 0)
		{
			above = s[len];
			below = s[i + 1];
		}
		else if (i == len)
		{
			above = s[i - 1];
			below = s[0];
		}
		else
		{
			above = s[i - 1];
			below = s[i + 1];
		}
		if (s[i] == min)
			below = min - 1;
		else if (s[i] == max)
			above = max + 1;
		if (s[i] < below || s[i] > above)
			return (-1);
	}
	return (0);
}

int	to_rsort(int **stacks, int next_nb_to_place)
{
	int	len;
	int	ret;
	int	min;
	int	max;
	int	i;

	len = stacks[B][0];
	stacks[B][0] = next_nb_to_place;
	min = INT_MAX;
	max = -1;
	i = -1;
	while (++i < len + 1)
	{
		if (stacks[B][i] > max)
			max = stacks[B][i];
		if (stacks[B][i] < min)
			min = stacks[B][i];
	}
	ret = to_rsort_algo(stacks, len, min, max);
	stacks[B][0] = len;
	if (ret < 0)
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
