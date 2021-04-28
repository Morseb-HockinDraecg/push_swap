#include "push_swap.h"

static void	init_tab_funct(void (*arr[8])(int **stacks))
{
	arr[sa] = instr_sa;
	arr[sb] = instr_sb;
	arr[ss] = instr_ss;
	arr[pa] = instr_pa;
	arr[pb] = instr_pb;
	arr[ra] = instr_ra;
	arr[rb] = instr_rb;
	arr[rr] = instr_rr;
	arr[rra] = instr_rra;
	arr[rrb] = instr_rrb;
	arr[rrr] = instr_rrr;
}

// void	send_instruc(int **stacks, int sorting)
// {
// 	void	(*arr[11])(int **stacks);
// 	int		i;

// 	init_tab_funct(arr);
// 	if (stacks[INSTRU][0])
// 	{
// 		i = 0;
// 		while (i++ < stacks[INSTRU][0])
// 			(*arr[stacks[INSTRU][i]])(stacks);
// 	}
// 	free(stacks[INSTRU]);
// 	stacks[INSTRU] = NULL;
// }

void	send_instruc(int **stacks)
{
	void	(*arr[11])(int **stacks);
	int		i;

	init_tab_funct(arr);
	if (stacks[INSTRU][0])
	{
		i = 0;
		while (i++ < stacks[INSTRU][0])
			(*arr[stacks[INSTRU][i]])(stacks);
	}
	free(stacks[INSTRU]);
	stacks[INSTRU] = NULL;
}
