#include "push_swap.h"

void	two_nbrs(int **stacks)
{
	if (stacks[A][1] > stacks[A][2])
		instr_sa(stacks);
}

void	three_nbrs(int **stacks)
{
	if (stacks[A][1] == 0)
	{
		instr_sa(stacks);
		instr_ra(stacks);
	}
	else if (stacks[A][1] == 1)
	{
		if (stacks[A][1] == 0)
			instr_sa(stacks);
		else
			instr_rra(stacks);
	}
	else
	{
		if (stacks[A][2] == 0)
			instr_ra(stacks);
		else
		{
			instr_sa(stacks);
			instr_rra(stacks);
		}
	}
}

void	last_three_nbrs(int **stacks)
{
	fill_substitute(stacks, stacks, stacks[A][0]);
	if (stacks[A][1] == 0)
	{
		instr_sa(stacks);
		instr_ra(stacks);
	}
	else if (stacks[A][1] == 1)
	{
		if (stacks[A][1] == 0)
			instr_sa(stacks);
		else
			instr_rra(stacks);
	}
	else
	{
		if (stacks[A][2] == 0)
			instr_ra(stacks);
		else
		{
			instr_sa(stacks);
			instr_rra(stacks);
		}
	}
}
