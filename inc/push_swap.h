#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

enum	e_stack_suite
{
	INSTRU = 2,
};

void	instr_sa(int **stacks);
void	instr_sb(int **stacks);
void	instr_ss(int **stacks);
void	instr_pa(int **stacks);
void	instr_pb(int **stacks);
void	instr_ra(int **stacks);
void	instr_rb(int **stacks);
void	instr_rr(int **stacks);
void	instr_rra(int **stacks);
void	instr_rrb(int **stacks);
void	instr_rrr(int **stacks);

void	two_nbrs(int **stacks);
void	three_nbrs(int **stacks);

int		is_sort(int **stacks);
int		to_rsort(int **stacks, int new_nb);
int		*sub_nbr(int **stack);
void	algo(int **stacks);
void	up_to_b(int **stacks, int to_top);
void	bottom_to_b(int **stacks, int to_top);
void	sort_b(int **stacks, int next_nb_to_place);
void	send_instruc(int **stacks);

#endif