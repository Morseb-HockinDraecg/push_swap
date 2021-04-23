#include "push_swap.h"

void	instr_rra(int **stacks)
{
	rra(stacks);
	write(1, "rra\n", cm_strlen("rra\n"));
}

void	instr_rrb(int **stacks)
{
	rrb(stacks);
	write(1, "rrb\n", cm_strlen("rrb\n"));
}

void	instr_rrr(int **stacks)
{
	rrr(stacks);
	write(1, "rrr\n", cm_strlen("rrr\n"));
}
