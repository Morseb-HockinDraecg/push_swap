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

void	to_rsort_algo_loop(int *s, int len, int **normy, int i)
{
	if (i == 0)
	{
		(*normy)[0] = s[len];
		(*normy)[1] = s[i + 1];
	}
	else if (i == len)
	{
		(*normy)[0] = s[i - 1];
		(*normy)[1] = s[0];
	}
	else
	{
		(*normy)[0] = s[i - 1];
		(*normy)[1] = s[i + 1];
	}
	if (s[i] == (*normy)[2])
		(*normy)[1] = (*normy)[2] - 1;
	else if (s[i] == (*normy)[3])
		(*normy)[0] = (*normy)[3] + 1;
}

static int	to_rsort_algo(int **stacks, int len, int min, int max)
{
	int	i;
	int	*s;
	int	above;
	int	below;
	int	*normy;

	above = 0;
	below = 0;
	normy = (int *)malloc(sizeof(int) * 4);
	s = stacks[B];
	i = -1;
	while (i++ < len)
	{
		normy[0] = above;
		normy[1] = below;
		normy[2] = min;
		normy[3] = max;
		to_rsort_algo_loop(s, len, &normy, i);
		if (s[i] < normy[1] || s[i] > normy[0])
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
