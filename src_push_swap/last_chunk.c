#include "push_swap.h"

void	sort_last_chunk(int **stacks)
{
	if (stacks[A][0] == 2)
		two_nbrs(stacks);
	else if (stacks[A][0] == 3)
		three_nbrs(stacks);
}
