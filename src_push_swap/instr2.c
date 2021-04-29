#include "push_swap.h"

void	instr_ra(int **stacks)
{
	fra(stacks);
	write(1, "ra\n", cm_strlen("ra\n"));
}

void	instr_rb(int **stacks)
{
	write(1, "rb\n", cm_strlen("rb\n"));
	(void)stacks;
}

void	instr_rr(int **stacks)
{
	fra(stacks);
	write(1, "rr\n", cm_strlen("rr\n"));
}
