#include "push_swap.h"

void	instr_ra(int **stacks)
{
	ra(stacks);
	write(1, "ra\n", cm_strlen("ra\n"));
}

void	instr_rb(int **stacks)
{
	rb(stacks);
	write(1, "rb\n", cm_strlen("rb\n"));
}

void	instr_rr(int **stacks)
{
	rr(stacks);
	write(1, "rr\n", cm_strlen("rr\n"));
}
