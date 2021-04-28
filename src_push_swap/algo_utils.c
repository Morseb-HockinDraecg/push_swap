#include "push_swap.h"

static void	copy_instru(int **stacks, int new_elem)
{
	int	*tmp;
	int	i;

	if (new_elem == -1)
		return ;
	tmp = (int *)malloc(sizeof(int) * (stacks[INSTRU][0] + 2));
	tmp[0] = stacks[INSTRU][0] + 1;
	tmp[tmp[0]] = new_elem;
	i = 0;
	while (i++ < stacks[INSTRU][0])
		tmp[i] = stacks[INSTRU][i];
	free(stacks[INSTRU]);
	stacks[INSTRU] = NULL;
	stacks[INSTRU] = tmp;
}

void	top_to_b(int **stacks, int to_top)
{
	if (to_top == 2)
		copy_instru(stacks, sa);
	else
	{
		while (--to_top)
			copy_instru(stacks, ra);
	}
}

void	bottom_to_b(int **stacks, int to_top)
{
	copy_instru(stacks, rra);
	if (to_top)
	{
		while (to_top--)
			copy_instru(stacks, rra);
	}
}

void	sort_b(int **stacks, int next_nb_to_place)
{
	int	loop;

	if (stacks[B][0] < 2)
	{
		copy_instru(stacks, pb);
		return ;
	}
	if (to_rsort(stacks, next_nb_to_place))
	{
		loop = 1;
		while (loop)
		{
			if (next_nb_to_place > stacks[B][1])
				// frrb(stacks);
				instr_rrb(stacks);
				// copy_instru(stacks, rb);
			else if (next_nb_to_place < stacks[B][1])
				// frb(stacks);
				instr_rb(stacks);
				// copy_instru(stacks, rrb);
	// send_instruc(stacks);
			loop = to_rsort(stacks, next_nb_to_place);
		}
	}
	copy_instru(stacks, pb);
}

void	clean_b(int **stacks)
{
	int	len;

	len = stacks[B][0];
	while (stacks[B][1] != (len - 1))
		instr_rrb(stacks);
	stacks[INSTRU] = (int *)malloc(sizeof(int) * 1);
	stacks[INSTRU][0] = 0;
	while (len--)
		copy_instru(stacks, pa);
	send_instruc(stacks);
}
