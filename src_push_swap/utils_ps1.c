#include "push_swap.h"

int	verif_nb_to_move(int **stacks, int up, int bot)
{
	if (up - (stacks[A][0] - bot) == 0 && up == stacks[A][0])
		printf("Nous avons un probleme ici ! HELP !!!\n");
	up_to_b(stacks, up);
	return (stacks[A][up]);
	(void)stacks;
	(void)up;
	(void)bot;
	return (-1);
}
