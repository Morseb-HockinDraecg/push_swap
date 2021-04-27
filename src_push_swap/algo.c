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
	{
		chunks = 3;
		while ((chunks * (k - 1)) > stacks[A][0])
			k--;
	}
	*r_k = (int)k;
	*r_chunks = (int)chunks;
}

static void	set_min_max(int *up, int *bottom, int **stacks, int min_max[2])
{
	int	i;
	int	demi_len;

	i = 0;
	demi_len = stacks[A][0] / 2;
	*up = stacks[A][0];
	*bottom = 0;
	while (i++ <= demi_len)
	{
		if ((unsigned)(stacks[A][i] - min_max[0] <= min_max[1] - min_max[0]))
		{
			*up = i - 1;
			break ;
		}
	}
	i = stacks[A][0] + 1;
	while (i-- > demi_len)
	{
		if ((unsigned)(stacks[A][i] - min_max[0] <= min_max[1] - min_max[0]))
		{
			*bottom = i - 1;
			break ;
		}
	}
}

//verif_nb_move en cas d egalite de move entre up et bot.
//a voir si "if" ou "else" pour la verif
static void	algoo(int min_max[2], int **stacks)
{
	int	up;
	int	bottom;
	int	next_nb_to_place;

	set_min_max(&up, &bottom, stacks, min_max);
	stacks[INSTRU] = (int *)malloc(sizeof(int) * 1);
	stacks[INSTRU][0] = 0;
	next_nb_to_place = -1;
	if (up)
	{
		if (up < (stacks[A][0] - bottom))
		{
			up_to_b(stacks, up);
			next_nb_to_place = stacks[A][up];
		}
		else if (up > (stacks[A][0] - bottom))
		{
			bottom_to_b(stacks, stacks[A][0] - bottom);
			next_nb_to_place = stacks[A][stacks[A][0] - bottom];
		}
		else
			next_nb_to_place = verif_nb_to_move(stacks, up, bottom);
	}
sort_b(stacks, next_nb_to_place); // a faire
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
			algoo(min_max, stacks);
	}
sort_last_chunk(stacks);	//voir si [a][0] > 3 !!!
	clean_b(stacks);
	instr_pa(stacks);
	return ;
}
