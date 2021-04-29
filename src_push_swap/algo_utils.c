#include "push_swap.h"

void	copy_instru(int **stacks, int new_elem)
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

static void	rang_r(int **stacks, int *rang_ra, int *rang_rra)
{
	int	i;

	i = 0;
	while (i++ < stacks[INSTRU][0])
	{
		if (stacks[INSTRU][i] == ra)
			*rang_ra = i;
		else if (stacks[INSTRU][i] == rra)
			*rang_rra = i;
	}
}

static void	sort_b_loop(int **stacks, int next_nb_to_place)
{
	int	rang_ra;
	int	rang_rra;

	rang_ra = -1;
	rang_rra = -1;
	rang_r(stacks, &rang_ra, &rang_rra);
	if (next_nb_to_place > stacks[B][1])
	{
		frrb(stacks);
		if (rang_rra == -1)
			copy_instru(stacks, rrb);
		else
			stacks[INSTRU][rang_rra] = rrr;
	}
	else if (next_nb_to_place < stacks[B][1])
	{
		frb(stacks);
		if (rang_ra == -1)
			copy_instru(stacks, rb);
		else
			stacks[INSTRU][rang_ra] = rr;
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
			sort_b_loop(stacks, next_nb_to_place);
			loop = to_rsort(stacks, next_nb_to_place);
		}
	}
	copy_instru(stacks, pb);
}

void	clean_b(int **stacks)
{
	int	len;
	int	rang;
	int	i;

	len = stacks[B][0];
	i = 0;
	while (i++ < len)
	{
		if (stacks[B][i] == (len -1))
		{
			rang = i;
			break ;
		}
	}
	while (stacks[B][1] != (len - 1))
	{
		if (rang < (len / 2))
		{
			frb(stacks);
			write(1, "rb\n", cm_strlen("rb\n"));
		}
		else
		{
			frrb(stacks);
			write(1, "rrb\n", cm_strlen("rrb\n"));
		}
	}
	stacks[INSTRU] = (int *)malloc(sizeof(int) * 1);
	stacks[INSTRU][0] = 0;
	while (len--)
		copy_instru(stacks, pa);
	send_instruc(stacks);
}
