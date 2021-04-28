#include "push_swap.h"

void	sort_last_chunk(int **stacks)
{
	int	min_max[2];

	min_max[0] = INT_MIN;
	min_max[1] = INT_MAX;
	while (stacks[A][0] > 3)
		loop_algo(min_max, stacks);
	if (stacks[A][0] < 2)
		return ;
	else if (stacks[A][0] == 2)
		two_nbrs(stacks);
	else if (stacks[A][0] == 3)
		last_three_nbrs(stacks);
}
