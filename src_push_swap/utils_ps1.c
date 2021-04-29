#include "push_swap.h"

int	verif_nb_to_move(int **stacks, int top, int bot)
{
	top_to_b(stacks, top);
	return (stacks[A][top]);
	(void)bot;
	return (stacks[A][top]);
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
