#include "push_swap.h"

void	two_nbrs(int **stacks)
{
	if (stacks[A][1] > stacks[A][2])
		instr_sa(stacks);
}

void	three_nbrs(int **stacks)
{
	if (stacks[A][1] < stacks[A][2] && stacks[A][1] < stacks[A][3])
	{
		instr_sa(stacks);
		instr_ra(stacks);
	}
	else if (stacks[A][1] < stacks[A][2] && stacks[A][1] > stacks[A][3])
	{
		if (stacks[A][1] < stacks[A][2] && stacks[A][1] < stacks[A][3])
			instr_sa(stacks);
		else
			instr_rra(stacks);
	}
	else
	{
		if (stacks[A][2] < stacks[A][1] && stacks[A][2] < stacks[A][3])
			instr_ra(stacks);
		else
		{
			instr_sa(stacks);
			instr_rra(stacks);
		}
	}
}