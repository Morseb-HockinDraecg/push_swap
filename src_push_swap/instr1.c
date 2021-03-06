#include "push_swap.h"

void	instr_sa(int **stacks)
{
	fsa(stacks);
	write(1, "sa\n", cm_strlen("sa\n"));
}

void	instr_sb(int **stacks)
{
	fsb(stacks);
	write(1, "sb\n", cm_strlen("sb\n"));
}

void	instr_ss(int **stacks)
{
	fss(stacks);
	write(1, "ss\n", cm_strlen("ss\n"));
}

void	instr_pa(int **stacks)
{
	fpa(stacks);
	write(1, "pa\n", cm_strlen("pa\n"));
}

void	instr_pb(int **stacks)
{
	fpb(stacks);
	write(1, "pb\n", cm_strlen("pb\n"));
}
