#include "push_swap.h"

static void	k_chunks_nbrs(int *r_k, int *r_chunks, int **stacks)
{
	float	k;
	float	chunks;

	k = 0.015 * stacks[A][0] + 3.5;
	if (k > (int)k)
		k = (int)k + 1;
	chunks = stacks[A][0] / k;
	if (chunks > (int)chunks)
		chunks = (int)chunks + 1;
	if (chunks < 3)
		chunks = 3;
	while ((int)(chunks * (k - 1)) >= stacks[A][0])
		k--;
	*r_k = (int)k;
	*r_chunks = (int)chunks;
}

static void	set_top_bottom(int *top, int *bottom, int **stacks, int min_max[2])
{
	int	i;
	int	demi_len;

	demi_len = stacks[A][0] / 2;
	*top = stacks[A][0];
	*bottom = 0;
	i = 0;
	while (i++ < demi_len)
	{
		if (stacks[A][i] >= min_max[0] && stacks[A][i] <= min_max[1])
		{
			*top = i;
			break ;
		}
	}
	i = stacks[A][0] + 1;
	while (--i > demi_len)
	{
		if (stacks[A][i] >= min_max[0] && stacks[A][i] <= min_max[1])
		{
			*bottom = i;
			break ;
		}
	}
}

void	loop_algo(int min_max[2], int **stacks)
{
	int	top;
	int	bottom;
	int	next_nb_to_place;

	set_top_bottom(&top, &bottom, stacks, min_max);
	stacks[INSTRU] = (int *)malloc(sizeof(int) * 1);
	stacks[INSTRU][0] = 0;
	next_nb_to_place = stacks[A][1];
	if (top != 1)
	{
		if (top < (stacks[A][0] - bottom))
		{
			top_to_b(stacks, top);
			next_nb_to_place = stacks[A][top];
		}
		else if (top > (stacks[A][0] - bottom) + 1)
		{
			bottom_to_b(stacks, stacks[A][0] - bottom);
			next_nb_to_place = stacks[A][bottom];
		}
		else
			next_nb_to_place = verif_nb_to_move(stacks, top, bottom);
	}
	sort_b(stacks, next_nb_to_place);
	send_instruc(stacks);
}

void	algo(int **stacks)
{
	int	k;
	int	i;
	int	chunks;
	int	loop;
	int	min_max[2];

	k_chunks_nbrs(&k, &chunks, stacks);
	i = 0;
	while (++i < k)
	{
		min_max[0] = (i - 1) * chunks;
		min_max[1] = i * chunks - 1;
		loop = chunks;
		while (loop--)
			loop_algo(min_max, stacks);
	}
	sort_last_chunk(stacks);
	// clean_b(stacks);
	return ;
}
